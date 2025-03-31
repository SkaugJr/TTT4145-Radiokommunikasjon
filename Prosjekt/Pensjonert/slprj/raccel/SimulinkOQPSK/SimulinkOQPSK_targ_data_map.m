    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtP.AWGNChannel_EbNo
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AWGNChannel_SignalPower
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Symbolmapping_tableData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Symbolmapping_bp01Data
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% rtP.Gain_Gain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtP.Pulseshaping_FILTER_COEFF
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtP.Delay_InitialCondition
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 15;

                    ;% rtP.Phaseoffset_Gain
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 16;

                    ;% rtP.FIRInterpolation_FILTER_COEFF
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 17;

                    ;% rtP.FIRDecimation_FILT
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 57;

                    ;% rtP.Constant_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 97;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtP.Gain1_Gain
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Bias_Bias
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ShiftArithmetic_DiagnosticForOORShift
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.moprdribiz
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.junrgsnmb0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.i5ilelgt54
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 12;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.kiqazyiq00
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.j33qtkq40m
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.pt5eromfcj
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.gbyowhygxr
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kviwuzsm51
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 5;

                    ;% rtDW.jhjvzmws0f
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 6;

                    ;% rtDW.jkwcjrsbfz
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 46;

                    ;% rtDW.mpkdim1qis
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 47;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.ate1uhb4qw
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hax1vszx2y
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.ikfemt5lt2
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dd5j4umhh2
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.eybefhgiyi
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.fkshk3as53
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kxculzx4lb
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.pbieyixh0q
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 12;

                    ;% rtDW.fm0vokcho4
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 20;

                    ;% rtDW.j43xnixtdn
                    section.data(5).logicalSrcIdx = 17;
                    section.data(5).dtTransOffset = 60;

                    ;% rtDW.krmeuxufvy
                    section.data(6).logicalSrcIdx = 18;
                    section.data(6).dtTransOffset = 140;

                    ;% rtDW.coksx155ze
                    section.data(7).logicalSrcIdx = 19;
                    section.data(7).dtTransOffset = 220;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.lpy5mzzed1
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.i1upjkvbfd
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.mahx1vfrrk
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.b1k03uckiu
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fextltf3bq
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.oj03j4ixuy
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.j4tyz1d51k
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kwhxs250ag
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 12;

                    ;% rtDW.jseolvrnea
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 13;

                    ;% rtDW.phw3qc5esn
                    section.data(8).logicalSrcIdx = 29;
                    section.data(8).dtTransOffset = 14;

                    ;% rtDW.on4d5t4ft3
                    section.data(9).logicalSrcIdx = 30;
                    section.data(9).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtDW.cxw1tnf414
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.krgyhlve5g
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.cgcq15tqz2
                    section.data(3).logicalSrcIdx = 33;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jdlamz5s1g
                    section.data(4).logicalSrcIdx = 34;
                    section.data(4).dtTransOffset = 627;

                    ;% rtDW.bxgvjqvv03
                    section.data(5).logicalSrcIdx = 35;
                    section.data(5).dtTransOffset = 629;

                    ;% rtDW.ax22qpdshl
                    section.data(6).logicalSrcIdx = 36;
                    section.data(6).dtTransOffset = 630;

                    ;% rtDW.g2xqaw3dz0
                    section.data(7).logicalSrcIdx = 37;
                    section.data(7).dtTransOffset = 631;

                    ;% rtDW.cuu1zsu24f
                    section.data(8).logicalSrcIdx = 38;
                    section.data(8).dtTransOffset = 632;

                    ;% rtDW.ipb0ry35mu
                    section.data(9).logicalSrcIdx = 39;
                    section.data(9).dtTransOffset = 1257;

                    ;% rtDW.d3xzp3vtkg
                    section.data(10).logicalSrcIdx = 40;
                    section.data(10).dtTransOffset = 1259;

                    ;% rtDW.e3grigdkp0
                    section.data(11).logicalSrcIdx = 41;
                    section.data(11).dtTransOffset = 1260;

                    ;% rtDW.kpo4xu3rlc
                    section.data(12).logicalSrcIdx = 42;
                    section.data(12).dtTransOffset = 1261;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.miuqblj25w
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% rtDW.bx2b103j3q
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.chgjvbcbzb
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.njjxls55cs
                    section.data(3).logicalSrcIdx = 46;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.gc3fngkune
                    section.data(4).logicalSrcIdx = 47;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.mbdjklko3i
                    section.data(5).logicalSrcIdx = 48;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.i5fyasx04o
                    section.data(6).logicalSrcIdx = 49;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.gkfm5uihb0
                    section.data(7).logicalSrcIdx = 50;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.miqhhd2uo2
                    section.data(8).logicalSrcIdx = 51;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.m2dn2xnnqj
                    section.data(9).logicalSrcIdx = 52;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.ksl0kmigx2
                    section.data(10).logicalSrcIdx = 53;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.cnhxmgap22
                    section.data(11).logicalSrcIdx = 54;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.mdfzrip4mj
                    section.data(12).logicalSrcIdx = 55;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.g1hyfm4tj3
                    section.data(13).logicalSrcIdx = 56;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.lmfcjcrcjv
                    section.data(14).logicalSrcIdx = 57;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.mb0j0kmjar
                    section.data(15).logicalSrcIdx = 58;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.hg0mobsir0
                    section.data(16).logicalSrcIdx = 59;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.lbsrysvv05
                    section.data(17).logicalSrcIdx = 60;
                    section.data(17).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2471231377;
    targMap.checksum1 = 1996571106;
    targMap.checksum2 = 1402774140;
    targMap.checksum3 = 1784209955;

