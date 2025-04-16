#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#
# SPDX-License-Identifier: GPL-3.0
#
# GNU Radio Python Flow Graph
# Title: Pakke & Burst Kommunikasjon
# Author: Kolbjørn Bølgen
# GNU Radio version: 3.10.9.2

from PyQt5 import Qt
from gnuradio import qtgui
from gnuradio import analog
from gnuradio import blocks
import pmt
from gnuradio import blocks, gr
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
from gnuradio import gr, pdu
from gnuradio import iio
from math import pi
from math import sqrt
import sip



class Pluto(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Pakke & Burst Kommunikasjon", catch_exceptions=True)
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Pakke & Burst Kommunikasjon")
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

        self.settings = Qt.QSettings("GNU Radio", "Pluto")

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
        self.payload_size_bytes = payload_size_bytes = 10
        self.pakker_ps = pakker_ps = 40
        self.header_size = header_size = 6
        self.duty_cycle_percent = duty_cycle_percent = 4
        self.crc_size = crc_size = 4
        self.signal_lengde = signal_lengde = int((header_size+payload_size_bytes+crc_size)*4*sps)
        self.datarate = datarate = (header_size + payload_size_bytes+crc_size)*8*0.5*pakker_ps/(duty_cycle_percent/100)
        self.vindu_lengde = vindu_lengde = int(signal_lengde*0.2)
        self.samp_rate = samp_rate = int(datarate*sps)
        self.access_key = access_key = '1101100111001110'
        self.vindu_taps = vindu_taps = [complex(t, t) for t in firdes.window(window.WIN_BLACKMAN, vindu_lengde, 0)]
        self.thresh = thresh = 1
        self.taps = taps = sps*15
        self.padding = padding = (samp_rate/pakker_ps-signal_lengde-vindu_lengde)
        self.hdr_format = hdr_format = digital.header_format_default(access_key, 0)
        self.excess_BW = excess_BW = 0.6
        self.QPSK = QPSK = digital.constellation_rect([0.707+0.707j, -0.707+0.707j, -0.707-0.707j, 0.707-0.707j], [0,1,2,3],
        4, 2, 2, 1, 1).base()
        self.LO_freq = LO_freq = 2.425e9

        ##################################################
        # Blocks
        ##################################################

        self.root_raised_cosine_filter_0_0 = filter.fir_filter_ccf(
            (int(sps/2)),
            firdes.root_raised_cosine(
                1,
                samp_rate,
                (samp_rate/sps),
                excess_BW,
                taps))
        self.root_raised_cosine_filter_0 = filter.interp_fir_filter_ccf(
            sps,
            firdes.root_raised_cosine(
                sps,
                samp_rate,
                (samp_rate/sps),
                excess_BW,
                taps))
        self.qtgui_time_sink_x_0_0 = qtgui.time_sink_f(
            256, #size
            samp_rate, #samp_rate
            'Correlate Output', #name
            1, #number of inputs
            None # parent
        )
        self.qtgui_time_sink_x_0_0.set_update_time(0.10)
        self.qtgui_time_sink_x_0_0.set_y_axis(-0.1, 1.1)

        self.qtgui_time_sink_x_0_0.set_y_label('Amplitude', "")

        self.qtgui_time_sink_x_0_0.enable_tags(True)
        self.qtgui_time_sink_x_0_0.set_trigger_mode(qtgui.TRIG_MODE_TAG, qtgui.TRIG_SLOPE_POS, 0.1, 0.0, 0, "packet_len")
        self.qtgui_time_sink_x_0_0.enable_autoscale(False)
        self.qtgui_time_sink_x_0_0.enable_grid(False)
        self.qtgui_time_sink_x_0_0.enable_axis_labels(True)
        self.qtgui_time_sink_x_0_0.enable_control_panel(False)
        self.qtgui_time_sink_x_0_0.enable_stem_plot(False)


        labels = ['', '', '', '', '',
            '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ['blue', 'red', 'green', 'black', 'cyan',
            'magenta', 'yellow', 'dark red', 'dark green', 'dark blue']
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]
        styles = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        markers = [-1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1]


        for i in range(1):
            if len(labels[i]) == 0:
                self.qtgui_time_sink_x_0_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_time_sink_x_0_0.set_line_label(i, labels[i])
            self.qtgui_time_sink_x_0_0.set_line_width(i, widths[i])
            self.qtgui_time_sink_x_0_0.set_line_color(i, colors[i])
            self.qtgui_time_sink_x_0_0.set_line_style(i, styles[i])
            self.qtgui_time_sink_x_0_0.set_line_marker(i, markers[i])
            self.qtgui_time_sink_x_0_0.set_line_alpha(i, alphas[i])

        self._qtgui_time_sink_x_0_0_win = sip.wrapinstance(self.qtgui_time_sink_x_0_0.qwidget(), Qt.QWidget)
        self.top_grid_layout.addWidget(self._qtgui_time_sink_x_0_0_win, 1, 2, 1, 2)
        for r in range(1, 2):
            self.top_grid_layout.setRowStretch(r, 1)
        for c in range(2, 4):
            self.top_grid_layout.setColumnStretch(c, 1)
        self.qtgui_time_sink_x_0 = qtgui.time_sink_c(
            signal_lengde, #size
            samp_rate, #samp_rate
            "", #name
            1, #number of inputs
            None # parent
        )
        self.qtgui_time_sink_x_0.set_update_time(0.10)
        self.qtgui_time_sink_x_0.set_y_axis(-1, 1)

        self.qtgui_time_sink_x_0.set_y_label('Amplitude', "")

        self.qtgui_time_sink_x_0.enable_tags(True)
        self.qtgui_time_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_TAG, qtgui.TRIG_SLOPE_POS, 0.0, 0, 0, "squelch_sob")
        self.qtgui_time_sink_x_0.enable_autoscale(False)
        self.qtgui_time_sink_x_0.enable_grid(False)
        self.qtgui_time_sink_x_0.enable_axis_labels(True)
        self.qtgui_time_sink_x_0.enable_control_panel(False)
        self.qtgui_time_sink_x_0.enable_stem_plot(False)


        labels = ['Signal 1', 'Signal 2', 'Signal 3', 'Signal 4', 'Signal 5',
            'Signal 6', 'Signal 7', 'Signal 8', 'Signal 9', 'Signal 10']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ['blue', 'red', 'green', 'black', 'cyan',
            'magenta', 'yellow', 'dark red', 'dark green', 'dark blue']
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]
        styles = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        markers = [-1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1]


        for i in range(2):
            if len(labels[i]) == 0:
                if (i % 2 == 0):
                    self.qtgui_time_sink_x_0.set_line_label(i, "Re{{Data {0}}}".format(i/2))
                else:
                    self.qtgui_time_sink_x_0.set_line_label(i, "Im{{Data {0}}}".format(i/2))
            else:
                self.qtgui_time_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_time_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_time_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_time_sink_x_0.set_line_style(i, styles[i])
            self.qtgui_time_sink_x_0.set_line_marker(i, markers[i])
            self.qtgui_time_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_time_sink_x_0_win = sip.wrapinstance(self.qtgui_time_sink_x_0.qwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_time_sink_x_0_win)
        self.qtgui_freq_sink_x_0 = qtgui.freq_sink_c(
            4096, #size
            window.WIN_BLACKMAN_hARRIS, #wintype
            0, #fc
            (samp_rate/(sps/2)), #bw
            "", #name
            1,
            None # parent
        )
        self.qtgui_freq_sink_x_0.set_update_time(0.1)
        self.qtgui_freq_sink_x_0.set_y_axis((-160), 10)
        self.qtgui_freq_sink_x_0.set_y_label('Relative Gain', 'dB')
        self.qtgui_freq_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.qtgui_freq_sink_x_0.enable_autoscale(False)
        self.qtgui_freq_sink_x_0.enable_grid(False)
        self.qtgui_freq_sink_x_0.set_fft_average(0.2)
        self.qtgui_freq_sink_x_0.enable_axis_labels(True)
        self.qtgui_freq_sink_x_0.enable_control_panel(False)
        self.qtgui_freq_sink_x_0.set_fft_window_normalized(True)



        labels = ['Etter CFC + RRC', 'Etter CFC + RRC', 'Tx', '', '',
            '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ["blue", "blue", "green", "black", "cyan",
            "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]

        for i in range(1):
            if len(labels[i]) == 0:
                self.qtgui_freq_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_freq_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_freq_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_freq_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_freq_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_freq_sink_x_0_win = sip.wrapinstance(self.qtgui_freq_sink_x_0.qwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_freq_sink_x_0_win)
        self.qtgui_eye_sink_x_0 = qtgui.eye_sink_c(
            (int(signal_lengde/2)), #size
            samp_rate, #samp_rate
            1, #number of inputs
            None
        )
        self.qtgui_eye_sink_x_0.set_update_time(0.1)
        self.qtgui_eye_sink_x_0.set_samp_per_symbol(1)
        self.qtgui_eye_sink_x_0.set_y_axis(-1, 1)

        self.qtgui_eye_sink_x_0.set_y_label('Amplitude', "")

        self.qtgui_eye_sink_x_0.enable_tags(True)
        self.qtgui_eye_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, 0, "")
        self.qtgui_eye_sink_x_0.enable_autoscale(False)
        self.qtgui_eye_sink_x_0.enable_grid(False)
        self.qtgui_eye_sink_x_0.enable_axis_labels(True)
        self.qtgui_eye_sink_x_0.enable_control_panel(False)


        labels = ['In-Phase', 'Quadrature', 'Signal 3', 'Signal 4', 'Signal 5',
            'Signal 6', 'Signal 7', 'Signal 8', 'Signal 9', 'Signal 10']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ['green', 'yellow', 'blue', 'blue', 'blue',
            'blue', 'blue', 'blue', 'blue', 'blue']
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]
        styles = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        markers = [1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1]


        for i in range(2):
            if len(labels[i]) == 0:
                if (i % 2 == 0):
                    self.qtgui_eye_sink_x_0.set_line_label(i, "Eye [Re{{Data {0}}}]".format(round(i/2)))
                else:
                    self.qtgui_eye_sink_x_0.set_line_label(i, "Eye [Im{{Data {0}}}]".format(round((i-1)/2)))
            else:
                self.qtgui_eye_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_eye_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_eye_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_eye_sink_x_0.set_line_style(i, styles[i])
            self.qtgui_eye_sink_x_0.set_line_marker(i, markers[i])
            self.qtgui_eye_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_eye_sink_x_0_win = sip.wrapinstance(self.qtgui_eye_sink_x_0.qwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_eye_sink_x_0_win)
        self.qtgui_const_sink_x_0_0 = qtgui.const_sink_c(
            (int(signal_lengde/2)), #size
            "", #name
            2, #number of inputs
            None # parent
        )
        self.qtgui_const_sink_x_0_0.set_update_time(0.1)
        self.qtgui_const_sink_x_0_0.set_y_axis((-2), 2)
        self.qtgui_const_sink_x_0_0.set_x_axis((-2), 2)
        self.qtgui_const_sink_x_0_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, "")
        self.qtgui_const_sink_x_0_0.enable_autoscale(False)
        self.qtgui_const_sink_x_0_0.enable_grid(False)
        self.qtgui_const_sink_x_0_0.enable_axis_labels(True)


        labels = ['Før CL+PLL', 'Etter CL+PLL', '', '', '',
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

        for i in range(2):
            if len(labels[i]) == 0:
                self.qtgui_const_sink_x_0_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_const_sink_x_0_0.set_line_label(i, labels[i])
            self.qtgui_const_sink_x_0_0.set_line_width(i, widths[i])
            self.qtgui_const_sink_x_0_0.set_line_color(i, colors[i])
            self.qtgui_const_sink_x_0_0.set_line_style(i, styles[i])
            self.qtgui_const_sink_x_0_0.set_line_marker(i, markers[i])
            self.qtgui_const_sink_x_0_0.set_line_alpha(i, alphas[i])

        self._qtgui_const_sink_x_0_0_win = sip.wrapinstance(self.qtgui_const_sink_x_0_0.qwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_const_sink_x_0_0_win)
        self.pdu_tagged_stream_to_pdu_2 = pdu.tagged_stream_to_pdu(gr.types.byte_t, 'packet_len')
        self.iio_pluto_source_0 = iio.fmcomms2_source_fc32('ip:192.168.2.1' if 'ip:192.168.2.1' else iio.get_pluto_uri(), [True, True], 4096)
        self.iio_pluto_source_0.set_len_tag_key("packet_len")
        self.iio_pluto_source_0.set_frequency(int(LO_freq))
        self.iio_pluto_source_0.set_samplerate(samp_rate)
        self.iio_pluto_source_0.set_gain_mode(0, 'hybrid')
        self.iio_pluto_source_0.set_gain(0, 64)
        self.iio_pluto_source_0.set_quadrature(True)
        self.iio_pluto_source_0.set_rfdc(True)
        self.iio_pluto_source_0.set_bbdc(True)
        self.iio_pluto_source_0.set_filter_params('Auto', '', 0, 0)
        self.iio_pluto_sink_0 = iio.fmcomms2_sink_fc32('ip:192.168.2.1' if 'ip:192.168.2.1' else iio.get_pluto_uri(), [True, True], 4096, False)
        self.iio_pluto_sink_0.set_len_tag_key('')
        self.iio_pluto_sink_0.set_bandwidth(20000000)
        self.iio_pluto_sink_0.set_frequency(int(LO_freq))
        self.iio_pluto_sink_0.set_samplerate(samp_rate)
        self.iio_pluto_sink_0.set_attenuation(0, 0)
        self.iio_pluto_sink_0.set_filter_params('Auto', '', 0, 0)
        self.digital_symbol_sync_xx_1 = digital.symbol_sync_cc(
            digital.TED_GARDNER,
            2,
            (2*pi*0.025),
            (sqrt(2)/2),
            1,
            (sps/4),
            1,
            digital.constellation_qpsk().base(),
            digital.IR_MMSE_8TAP,
            128,
            )
        self.digital_protocol_formatter_bb_0 = digital.protocol_formatter_bb(hdr_format, "packet_len")
        self.digital_fll_band_edge_cc_0 = digital.fll_band_edge_cc(sps, excess_BW, (11*sps), 0.025)
        self.digital_diff_encoder_bb_0 = digital.diff_encoder_bb(4, digital.DIFF_DIFFERENTIAL)
        self.digital_diff_decoder_bb_0 = digital.diff_decoder_bb(4, digital.DIFF_DIFFERENTIAL)
        self.digital_crc32_bb_1 = digital.crc32_bb(True, "packet_len", True)
        self.digital_crc32_bb_0 = digital.crc32_bb(False, "packet_len", True)
        self.digital_costas_loop_cc_0 = digital.costas_loop_cc((2*pi*0.04), 4, False)
        self.digital_correlate_access_code_xx_ts_0 = digital.correlate_access_code_bb_ts(access_key,
          thresh, 'packet_len')
        self.digital_constellation_encoder_bc_0 = digital.constellation_encoder_bc(QPSK)
        self.digital_constellation_decoder_cb_0 = digital.constellation_decoder_cb(QPSK)
        self.digital_burst_shaper_xx_0 = digital.burst_shaper_cc(vindu_taps, (int(padding/2)), (int(padding/2)), True, "burst_len")
        self.blocks_unpack_k_bits_bb_0 = blocks.unpack_k_bits_bb(2)
        self.blocks_uchar_to_float_0_0_0 = blocks.uchar_to_float()
        self.blocks_tagged_stream_mux_0_0_0 = blocks.tagged_stream_mux(gr.sizeof_char*1, 'packet_len', 0)
        self.blocks_tagged_stream_multiply_length_0 = blocks.tagged_stream_multiply_length(gr.sizeof_gr_complex*1, 'packet_len', 4)
        self.blocks_stream_to_tagged_stream_1 = blocks.stream_to_tagged_stream(gr.sizeof_gr_complex, 1, signal_lengde, "burst_len")
        self.blocks_stream_to_tagged_stream_0 = blocks.stream_to_tagged_stream(gr.sizeof_char, 1, payload_size_bytes, "packet_len")
        self.blocks_skiphead_0_0 = blocks.skiphead(gr.sizeof_gr_complex*1, (int(taps/2)))
        self.blocks_repack_bits_bb_1 = blocks.repack_bits_bb(1, 8, "packet_len", False, gr.GR_MSB_FIRST)
        self.blocks_repack_bits_bb_0 = blocks.repack_bits_bb(8, 1, "packet_len", False, gr.GR_MSB_FIRST)
        self.blocks_pack_k_bits_bb_0 = blocks.pack_k_bits_bb(2)
        self.blocks_message_debug_0 = blocks.message_debug(True, gr.log_levels.info)
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, 'TxData/datapakker10bytesCounter', False, 0, 0)
        self.blocks_file_source_0.set_begin_tag(pmt.PMT_NIL)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, 'RxData.txt', False)
        self.blocks_file_sink_0.set_unbuffered(False)
        self.analog_pwr_squelch_xx_0 = analog.pwr_squelch_cc((-6), 0.2, 0, True)


        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.pdu_tagged_stream_to_pdu_2, 'pdus'), (self.blocks_message_debug_0, 'log'))
        self.connect((self.analog_pwr_squelch_xx_0, 0), (self.digital_fll_band_edge_cc_0, 0))
        self.connect((self.analog_pwr_squelch_xx_0, 0), (self.qtgui_time_sink_x_0, 0))
        self.connect((self.blocks_file_source_0, 0), (self.blocks_stream_to_tagged_stream_0, 0))
        self.connect((self.blocks_pack_k_bits_bb_0, 0), (self.digital_diff_encoder_bb_0, 0))
        self.connect((self.blocks_repack_bits_bb_0, 0), (self.blocks_pack_k_bits_bb_0, 0))
        self.connect((self.blocks_repack_bits_bb_1, 0), (self.digital_crc32_bb_1, 0))
        self.connect((self.blocks_skiphead_0_0, 0), (self.blocks_tagged_stream_multiply_length_0, 0))
        self.connect((self.blocks_stream_to_tagged_stream_0, 0), (self.digital_crc32_bb_0, 0))
        self.connect((self.blocks_stream_to_tagged_stream_1, 0), (self.digital_burst_shaper_xx_0, 0))
        self.connect((self.blocks_tagged_stream_multiply_length_0, 0), (self.blocks_stream_to_tagged_stream_1, 0))
        self.connect((self.blocks_tagged_stream_mux_0_0_0, 0), (self.blocks_repack_bits_bb_0, 0))
        self.connect((self.blocks_uchar_to_float_0_0_0, 0), (self.qtgui_time_sink_x_0_0, 0))
        self.connect((self.blocks_unpack_k_bits_bb_0, 0), (self.digital_correlate_access_code_xx_ts_0, 0))
        self.connect((self.digital_burst_shaper_xx_0, 0), (self.iio_pluto_sink_0, 0))
        self.connect((self.digital_constellation_decoder_cb_0, 0), (self.digital_diff_decoder_bb_0, 0))
        self.connect((self.digital_constellation_encoder_bc_0, 0), (self.root_raised_cosine_filter_0, 0))
        self.connect((self.digital_correlate_access_code_xx_ts_0, 0), (self.blocks_repack_bits_bb_1, 0))
        self.connect((self.digital_correlate_access_code_xx_ts_0, 0), (self.blocks_uchar_to_float_0_0_0, 0))
        self.connect((self.digital_costas_loop_cc_0, 0), (self.digital_constellation_decoder_cb_0, 0))
        self.connect((self.digital_costas_loop_cc_0, 0), (self.qtgui_const_sink_x_0_0, 1))
        self.connect((self.digital_costas_loop_cc_0, 0), (self.qtgui_eye_sink_x_0, 0))
        self.connect((self.digital_crc32_bb_0, 0), (self.blocks_tagged_stream_mux_0_0_0, 1))
        self.connect((self.digital_crc32_bb_0, 0), (self.digital_protocol_formatter_bb_0, 0))
        self.connect((self.digital_crc32_bb_1, 0), (self.blocks_file_sink_0, 0))
        self.connect((self.digital_crc32_bb_1, 0), (self.pdu_tagged_stream_to_pdu_2, 0))
        self.connect((self.digital_diff_decoder_bb_0, 0), (self.blocks_unpack_k_bits_bb_0, 0))
        self.connect((self.digital_diff_encoder_bb_0, 0), (self.digital_constellation_encoder_bc_0, 0))
        self.connect((self.digital_fll_band_edge_cc_0, 0), (self.root_raised_cosine_filter_0_0, 0))
        self.connect((self.digital_protocol_formatter_bb_0, 0), (self.blocks_tagged_stream_mux_0_0_0, 0))
        self.connect((self.digital_symbol_sync_xx_1, 0), (self.digital_costas_loop_cc_0, 0))
        self.connect((self.digital_symbol_sync_xx_1, 0), (self.qtgui_const_sink_x_0_0, 0))
        self.connect((self.iio_pluto_source_0, 0), (self.analog_pwr_squelch_xx_0, 0))
        self.connect((self.root_raised_cosine_filter_0, 0), (self.blocks_skiphead_0_0, 0))
        self.connect((self.root_raised_cosine_filter_0_0, 0), (self.digital_symbol_sync_xx_1, 0))
        self.connect((self.root_raised_cosine_filter_0_0, 0), (self.qtgui_freq_sink_x_0, 0))


    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "Pluto")
        self.settings.setValue("geometry", self.saveGeometry())
        self.stop()
        self.wait()

        event.accept()

    def get_sps(self):
        return self.sps

    def set_sps(self, sps):
        self.sps = sps
        self.set_samp_rate(int(self.datarate*self.sps))
        self.set_signal_lengde(int((self.header_size+self.payload_size_bytes+self.crc_size)*4*self.sps))
        self.set_taps(self.sps*15)
        self.qtgui_freq_sink_x_0.set_frequency_range(0, (self.samp_rate/(self.sps/2)))
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))
        self.root_raised_cosine_filter_0_0.set_taps(firdes.root_raised_cosine(1, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_payload_size_bytes(self):
        return self.payload_size_bytes

    def set_payload_size_bytes(self, payload_size_bytes):
        self.payload_size_bytes = payload_size_bytes
        self.set_datarate((self.header_size + self.payload_size_bytes+self.crc_size)*8*0.5*self.pakker_ps/(self.duty_cycle_percent/100))
        self.set_signal_lengde(int((self.header_size+self.payload_size_bytes+self.crc_size)*4*self.sps))
        self.blocks_stream_to_tagged_stream_0.set_packet_len(self.payload_size_bytes)
        self.blocks_stream_to_tagged_stream_0.set_packet_len_pmt(self.payload_size_bytes)

    def get_pakker_ps(self):
        return self.pakker_ps

    def set_pakker_ps(self, pakker_ps):
        self.pakker_ps = pakker_ps
        self.set_datarate((self.header_size + self.payload_size_bytes+self.crc_size)*8*0.5*self.pakker_ps/(self.duty_cycle_percent/100))
        self.set_padding((self.samp_rate/self.pakker_ps-self.signal_lengde-self.vindu_lengde))

    def get_header_size(self):
        return self.header_size

    def set_header_size(self, header_size):
        self.header_size = header_size
        self.set_datarate((self.header_size + self.payload_size_bytes+self.crc_size)*8*0.5*self.pakker_ps/(self.duty_cycle_percent/100))
        self.set_signal_lengde(int((self.header_size+self.payload_size_bytes+self.crc_size)*4*self.sps))

    def get_duty_cycle_percent(self):
        return self.duty_cycle_percent

    def set_duty_cycle_percent(self, duty_cycle_percent):
        self.duty_cycle_percent = duty_cycle_percent
        self.set_datarate((self.header_size + self.payload_size_bytes+self.crc_size)*8*0.5*self.pakker_ps/(self.duty_cycle_percent/100))

    def get_crc_size(self):
        return self.crc_size

    def set_crc_size(self, crc_size):
        self.crc_size = crc_size
        self.set_datarate((self.header_size + self.payload_size_bytes+self.crc_size)*8*0.5*self.pakker_ps/(self.duty_cycle_percent/100))
        self.set_signal_lengde(int((self.header_size+self.payload_size_bytes+self.crc_size)*4*self.sps))

    def get_signal_lengde(self):
        return self.signal_lengde

    def set_signal_lengde(self, signal_lengde):
        self.signal_lengde = signal_lengde
        self.set_padding((self.samp_rate/self.pakker_ps-self.signal_lengde-self.vindu_lengde))
        self.set_vindu_lengde(int(self.signal_lengde*0.2))
        self.blocks_stream_to_tagged_stream_1.set_packet_len(self.signal_lengde)
        self.blocks_stream_to_tagged_stream_1.set_packet_len_pmt(self.signal_lengde)

    def get_datarate(self):
        return self.datarate

    def set_datarate(self, datarate):
        self.datarate = datarate
        self.set_samp_rate(int(self.datarate*self.sps))

    def get_vindu_lengde(self):
        return self.vindu_lengde

    def set_vindu_lengde(self, vindu_lengde):
        self.vindu_lengde = vindu_lengde
        self.set_padding((self.samp_rate/self.pakker_ps-self.signal_lengde-self.vindu_lengde))
        self.set_vindu_taps([complex(t, t) for t in firdes.window(window.WIN_BLACKMAN, self.vindu_lengde, 0)])

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.set_padding((self.samp_rate/self.pakker_ps-self.signal_lengde-self.vindu_lengde))
        self.iio_pluto_sink_0.set_samplerate(self.samp_rate)
        self.iio_pluto_source_0.set_samplerate(self.samp_rate)
        self.qtgui_eye_sink_x_0.set_samp_rate(self.samp_rate)
        self.qtgui_freq_sink_x_0.set_frequency_range(0, (self.samp_rate/(self.sps/2)))
        self.qtgui_time_sink_x_0.set_samp_rate(self.samp_rate)
        self.qtgui_time_sink_x_0_0.set_samp_rate(self.samp_rate)
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))
        self.root_raised_cosine_filter_0_0.set_taps(firdes.root_raised_cosine(1, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_access_key(self):
        return self.access_key

    def set_access_key(self, access_key):
        self.access_key = access_key
        self.set_hdr_format(digital.header_format_default(self.access_key, 0))

    def get_vindu_taps(self):
        return self.vindu_taps

    def set_vindu_taps(self, vindu_taps):
        self.vindu_taps = vindu_taps

    def get_thresh(self):
        return self.thresh

    def set_thresh(self, thresh):
        self.thresh = thresh

    def get_taps(self):
        return self.taps

    def set_taps(self, taps):
        self.taps = taps
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))
        self.root_raised_cosine_filter_0_0.set_taps(firdes.root_raised_cosine(1, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_padding(self):
        return self.padding

    def set_padding(self, padding):
        self.padding = padding

    def get_hdr_format(self):
        return self.hdr_format

    def set_hdr_format(self, hdr_format):
        self.hdr_format = hdr_format

    def get_excess_BW(self):
        return self.excess_BW

    def set_excess_BW(self, excess_BW):
        self.excess_BW = excess_BW
        self.root_raised_cosine_filter_0.set_taps(firdes.root_raised_cosine(self.sps, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))
        self.root_raised_cosine_filter_0_0.set_taps(firdes.root_raised_cosine(1, self.samp_rate, (self.samp_rate/self.sps), self.excess_BW, self.taps))

    def get_QPSK(self):
        return self.QPSK

    def set_QPSK(self, QPSK):
        self.QPSK = QPSK
        self.digital_constellation_decoder_cb_0.set_constellation(self.QPSK)
        self.digital_constellation_encoder_bc_0.set_constellation(self.QPSK)

    def get_LO_freq(self):
        return self.LO_freq

    def set_LO_freq(self, LO_freq):
        self.LO_freq = LO_freq
        self.iio_pluto_sink_0.set_frequency(int(self.LO_freq))
        self.iio_pluto_source_0.set_frequency(int(self.LO_freq))




def main(top_block_cls=Pluto, options=None):

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
