#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#
# SPDX-License-Identifier: GPL-3.0
#
# GNU Radio Python Flow Graph
# Title: Not titled yet
# Author: Kolbjørn Bølgen
# GNU Radio version: 3.10.9.2

from PyQt5 import Qt
from gnuradio import qtgui
from gnuradio import analog
from gnuradio import blocks
from gnuradio import digital
from gnuradio import filter
from gnuradio.filter import firdes
from gnuradio import gr
from gnuradio.fft import window
import sys
import signal
from PyQt5 import Qt
from argparse import ArgumentParser
from gnuradio.eng_arg import eng_float, intx
from gnuradio import eng_notation
from math import pi
from math import sqrt
import sip



class FormatTest(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Not titled yet", catch_exceptions=True)
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Not titled yet")
        qtgui.util.check_set_qss()
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except BaseException as exc:
            print(f"Qt GUI: Could not set Icon: {str(exc)}", file=sys.stderr)
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "FormatTest")

        try:
            geometry = self.settings.value("geometry")
            if geometry:
                self.restoreGeometry(geometry)
        except BaseException as exc:
            print(f"Qt GUI: Could not restore geometry: {str(exc)}", file=sys.stderr)

        ##################################################
        # Variables
        ##################################################
        self.sps = sps = 6
        self.datarate = datarate = 80e3
        self.taps = taps = sps*4
        self.samp_rate = samp_rate = int(datarate*sps)
        self.excess_BW = excess_BW = 0.45
        self.access_key = access_key = '1110001101011111'
        self.thresh = thresh = 1
        self.rrc_taps = rrc_taps = firdes.root_raised_cosine(1.0,samp_rate,samp_rate/sps,excess_BW,taps)
        self.hdr_format = hdr_format = digital.header_format_default(access_key, 0)
        self.QPSK = QPSK = digital.constellation_rect([0.707+0.707j, -0.707+0.707j, -0.707-0.707j, 0.707-0.707j], [0,1,2,3],
        4, 2, 2, 1, 1).base()

        ##################################################
        # Blocks
        ##################################################

        self.root_raised_cosine_filter_0 = filter.interp_fir_filter_ccf(
            sps,
            firdes.root_raised_cosine(
                sps,
                samp_rate,
                (samp_rate/sps),
                excess_BW,
                taps))
        self.qtgui_const_sink_x_0 = qtgui.const_sink_c(
            (int(samp_rate/10)), #size
            "", #name
            1, #number of inputs
            None # parent
        )
        self.qtgui_const_sink_x_0.set_update_time(0.10)
        self.qtgui_const_sink_x_0.set_y_axis((-2), 2)
        self.qtgui_const_sink_x_0.set_x_axis((-2), 2)
        self.qtgui_const_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, "")
        self.qtgui_const_sink_x_0.enable_autoscale(False)
        self.qtgui_const_sink_x_0.enable_grid(False)
        self.qtgui_const_sink_x_0.enable_axis_labels(True)


        labels = ['', '', '', '', '',
            '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
            "magenta", "yellow", "dark red", "dark green", "dark blue"]
        styles = [0, 0, 0, 0, 0,
            0, 0, 0, 0, 0]
        markers = [0, 0, 0, 0, 0,
            0, 0, 0, 0, 0]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]

        for i in range(1):
            if len(labels[i]) == 0:
                self.qtgui_const_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_const_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_const_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_const_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_const_sink_x_0.set_line_style(i, styles[i])
            self.qtgui_const_sink_x_0.set_line_marker(i, markers[i])
            self.qtgui_const_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_const_sink_x_0_win = sip.wrapinstance(self.qtgui_const_sink_x_0.qwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_const_sink_x_0_win)
        self.digital_protocol_formatter_bb_0 = digital.protocol_formatter_bb(hdr_format, "packet_len")
        self.digital_diff_encoder_bb_0 = digital.diff_encoder_bb(4, digital.DIFF_DIFFERENTIAL)
        self.digital_crc32_bb_0 = digital.crc32_bb(False, "packet_len", True)
        self.digital_constellation_encoder_bc_0 = digital.constellation_encoder_bc(QPSK)
        self.blocks_throttle2_0_0 = blocks.throttle( gr.sizeof_gr_complex*1, samp_rate, True, 0 if "auto" == "auto" else max( int(float(0.1) * samp_rate) if "auto" == "time" else int(0.1), 1) )
        self.blocks_tagged_stream_mux_0_0_0 = blocks.tagged_stream_mux(gr.sizeof_char*1, 'packet_len', 0)
        self.blocks_stream_to_tagged_stream_0 = blocks.stream_to_tagged_stream(gr.sizeof_char, 1, 10, "packet_len")
        self.blocks_repack_bits_bb_0 = blocks.repack_bits_bb(8, 1, "packet_len", False, gr.GR_MSB_FIRST)
        self.blocks_pack_k_bits_bb_0 = blocks.pack_k_bits_bb(2)
        self.blocks_head_0 = blocks.head(gr.sizeof_gr_complex*1, samp_rate)
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_gr_complex*1, 'SimData/TxKontData.bin', False)
        self.blocks_file_sink_1.set_unbuffered(False)
        self.analog_random_uniform_source_x_0 = analog.random_uniform_source_b(0, 256, 0)


        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_random_uniform_source_x_0, 0), (self.blocks_stream_to_tagged_stream_0, 0))
        self.connect((self.blocks_head_0, 0), (self.blocks_file_sink_1, 0))
        self.connect((self.blocks_pack_k_bits_bb_0, 0), (self.digital_diff_encoder_bb_0, 0))
        self.connect((self.blocks_repack_bits_bb_0, 0), (self.blocks_pack_k_bits_bb_0, 0))
        self.connect((self.blocks_stream_to_tagged_stream_0, 0), (self.digital_crc32_bb_0, 0))
        self.connect((self.blocks_tagged_stream_mux_0_0_0, 0), (self.blocks_repack_bits_bb_0, 0))
        self.connect((self.blocks_throttle2_0_0, 0), (self.blocks_head_0, 0))
        self.connect((self.blocks_throttle2_0_0, 0), (self.qtgui_const_sink_x_0, 0))
        self.connect((self.digital_constellation_encoder_bc_0, 0), (self.root_raised_cosine_filter_0, 0))
        self.connect((self.digital_crc32_bb_0, 0), (self.blocks_tagged_stream_mux_0_0_0, 1))
        self.connect((self.digital_crc32_bb_0, 0), (self.digital_protocol_formatter_bb_0, 0))
        self.connect((self.digital_diff_encoder_bb_0, 0), (self.digital_constellation_encoder_bc_0, 0))
        self.connect((self.digital_protocol_formatter_bb_0, 0), (self.blocks_tagged_stream_mux_0_0_0, 0))
        self.connect((self.root_raised_cosine_filter_0, 0), (self.blocks_throttle2_0_0, 0))


    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "FormatTest")
        self.settings.setValue("geometry", self.saveGeometry())
        self.stop()
        self.wait()

        event.accept()

    def get_sps(self):
        return self.sps

    def set_sps(self, sps):
        self.sps = sps
        self.set_rrc_taps(firdes.root_raised_cosine(1.0,self.samp_rate,self.samp_rate/self.sps,self.excess_BW,self.taps))
        self.set_samp_rate(int(self.datarate*self.sps))
        self.set_taps(self.sps*4)
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_datarate(self):
        return self.datarate

    def set_datarate(self, datarate):
        self.datarate = datarate
        self.set_samp_rate(int(self.datarate*self.sps))

    def get_taps(self):
        return self.taps

    def set_taps(self, taps):
        self.taps = taps
        self.set_rrc_taps(firdes.root_raised_cosine(1.0,self.samp_rate,self.samp_rate/self.sps,self.excess_BW,self.taps))
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.set_rrc_taps(firdes.root_raised_cosine(1.0,self.samp_rate,self.samp_rate/self.sps,self.excess_BW,self.taps))
        self.blocks_head_0.set_length(self.samp_rate)
        self.blocks_throttle2_0_0.set_sample_rate(self.samp_rate)
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_excess_BW(self):
        return self.excess_BW

    def set_excess_BW(self, excess_BW):
        self.excess_BW = excess_BW
        self.set_rrc_taps(firdes.root_raised_cosine(1.0,self.samp_rate,self.samp_rate/self.sps,self.excess_BW,self.taps))
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_access_key(self):
        return self.access_key

    def set_access_key(self, access_key):
        self.access_key = access_key
        self.set_hdr_format(digital.header_format_default(self.access_key, 0))

    def get_thresh(self):
        return self.thresh

    def set_thresh(self, thresh):
        self.thresh = thresh

    def get_rrc_taps(self):
        return self.rrc_taps

    def set_rrc_taps(self, rrc_taps):
        self.rrc_taps = rrc_taps

    def get_hdr_format(self):
        return self.hdr_format

    def set_hdr_format(self, hdr_format):
        self.hdr_format = hdr_format

    def get_QPSK(self):
        return self.QPSK

    def set_QPSK(self, QPSK):
        self.QPSK = QPSK
        self.digital_constellation_encoder_bc_0.set_constellation(self.QPSK)




def main(top_block_cls=FormatTest, options=None):

    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()

    tb.start()

    tb.show()

    def sig_handler(sig=None, frame=None):
        tb.stop()
        tb.wait()

        Qt.QApplication.quit()

    signal.signal(signal.SIGINT, sig_handler)
    signal.signal(signal.SIGTERM, sig_handler)

    timer = Qt.QTimer()
    timer.start(500)
    timer.timeout.connect(lambda: None)

    qapp.exec_()

if __name__ == '__main__':
    main()
