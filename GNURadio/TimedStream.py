import time
import numpy as np
from gnuradio import gr

class timed_stream(gr.sync_block):
    def __init__(self, period_ms=1000, packet_size=9):
        gr.sync_block.__init__(self,
            name="Timed Stream",
            in_sig=[np.uint8],  
            out_sig=[np.uint8])  
        
        self.period_ms = period_ms / 1000.0  
        self.packet_size = packet_size  
        self.first_packet_sent = False  
        self.last_send_time = time.time()
        self.eof_reached = False  

    def work(self, input_items, output_items):
        current_time = time.time()
        in_data = input_items[0]
        out_data = output_items[0]

        if len(out_data) == 0:
            return 0  # GNURadio har ikke allokert plass denne gangen

        # Første pakke: nullfyll
        if not self.first_packet_sent:
            print("Sender init-pakke med nuller")
            packet_length = min(len(out_data), self.packet_size)
            out_data[:packet_length] = np.zeros(packet_length, dtype=np.uint8)
            self.first_packet_sent = True
            self.last_send_time = current_time
            return packet_length  

        # Send nye pakker hver period_ms
        elif current_time - self.last_send_time >= self.period_ms:
            if len(in_data) == 0:
                if not self.eof_reached:
                    print("Sender siste pakke med nuller")
                    packet_length = min(len(out_data), self.packet_size)
                    out_data[:packet_length] = np.zeros(packet_length, dtype=np.uint8)
                    self.eof_reached = True  
                    return packet_length
                else:
                    return 0  # Har sendt EOF, ingen flere pakker

            else:
                # Hvis vi har færre bytes enn en full pakke, pad med nuller
                packet_length = min(len(out_data), self.packet_size)
                out_data[:len(in_data)] = in_data
                if len(in_data) < packet_length:
                    out_data[len(in_data):packet_length] = np.zeros(packet_length - len(in_data), dtype=np.uint8)
                
                self.last_send_time = current_time
                return packet_length

        return 0   







