  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (bms_f4_P)
    ;%
      section.nData     = 225;
      section.data(225)  = dumData; %prealloc
      
	  ;% bms_f4_P.CellCurrentLimitThreshold_Fault
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_P.CellCurrentLimitThreshold_Warning
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bms_f4_P.CellTemperatureLimitThreshold_Fault
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bms_f4_P.CellTemperatureLimitThreshold_Warning
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bms_f4_P.CellVoltageLimitHigh_Fault
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bms_f4_P.CellVoltageLimitHigh_Warning
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bms_f4_P.CellVoltageLimitLow_Fault
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bms_f4_P.CellVoltageLimitLow_Warning
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% bms_f4_P.DeltaVTargetMin
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% bms_f4_P.DrivetrainEnDelay
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% bms_f4_P.VbattMin
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% bms_f4_P.VbattThersholdChrg
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% bms_f4_P.VbattThresholdDis
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% bms_f4_P.balancingRelaxationTime
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% bms_f4_P.balancingTime
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainval
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_d
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_h
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_n
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_o
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_d
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_l
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_m
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_m
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_mg
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_lh
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_do
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_l
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_nt
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_mu
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_p
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_i
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_p
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_i
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_o
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_e
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_h
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_l
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_m3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_f
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_oo
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_e
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_g
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_o
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_p
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_ou
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_j
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_g
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_k
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_b
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_jp
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_ge
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_ks
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_dx
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_g2
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_k
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_c
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_lq
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_gd
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_c5
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_a
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_oq
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_b
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_b
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_n
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_dk
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_f5
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_pb
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_co
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_on
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_i0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_gd
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_f
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_c
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_h
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_hb
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_cu
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_lt
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_e1
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_pz
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainva_e
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_k
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_g4
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_m
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_pk
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_dc
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_o
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_k0
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_nb
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_j
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_p
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_a
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_a5
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_hw
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_ae
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_md
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 103;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_dv
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 104;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_UpperS_d
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 105;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_d
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 106;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_lm
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 107;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_l1
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 108;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_eg
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 109;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_do
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 110;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_ae
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 111;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_i
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 112;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_hx
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 113;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_em
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 114;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_lx
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 115;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_f
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 116;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_ng
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 117;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_oi
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 118;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gain_pkl
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 119;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_ln
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 120;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_ei
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 121;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_LowerS_i
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 122;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gain_lxl
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 123;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_mf
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 124;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_cc
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 125;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_cp
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 126;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_ea
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 127;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_mz
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 128;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_jh
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 129;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_ig
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 130;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_gainv_ol
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 131;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_IC_m1
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 132;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Upper_m0
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 133;
	
	  ;% bms_f4_P.DiscreteTimeIntegrator_Lower_ou
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 134;
	
	  ;% bms_f4_P.nDLookupTable_tableData
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 135;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 138;
	
	  ;% bms_f4_P.Gain_Gain
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 141;
	
	  ;% bms_f4_P.nDLookupTable_tableData_f
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 142;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_o
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 145;
	
	  ;% bms_f4_P.Gain_Gain_f
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 148;
	
	  ;% bms_f4_P.nDLookupTable_tableData_e
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 149;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_m
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 152;
	
	  ;% bms_f4_P.Gain_Gain_m
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 155;
	
	  ;% bms_f4_P.nDLookupTable_tableData_a
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 156;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_c
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 159;
	
	  ;% bms_f4_P.Gain_Gain_fa
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 162;
	
	  ;% bms_f4_P.nDLookupTable_tableData_h
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 163;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_h
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 166;
	
	  ;% bms_f4_P.Gain_Gain_l
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 169;
	
	  ;% bms_f4_P.nDLookupTable_tableData_m
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 170;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_g
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 173;
	
	  ;% bms_f4_P.Gain_Gain_c
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 176;
	
	  ;% bms_f4_P.nDLookupTable_tableData_j
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 177;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_gg
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 180;
	
	  ;% bms_f4_P.Gain_Gain_n
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 183;
	
	  ;% bms_f4_P.nDLookupTable_tableData_i
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 184;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_p
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 187;
	
	  ;% bms_f4_P.Gain_Gain_o
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 190;
	
	  ;% bms_f4_P.nDLookupTable_tableData_fr
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 191;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_j
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 194;
	
	  ;% bms_f4_P.Gain_Gain_la
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 197;
	
	  ;% bms_f4_P.nDLookupTable_tableData_g
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 198;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_k
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 201;
	
	  ;% bms_f4_P.Gain_Gain_c4
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 204;
	
	  ;% bms_f4_P.nDLookupTable_tableData_l
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 205;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_i
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 208;
	
	  ;% bms_f4_P.Gain_Gain_p
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 211;
	
	  ;% bms_f4_P.nDLookupTable_tableData_md
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 212;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_pr
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 215;
	
	  ;% bms_f4_P.Gain_Gain_d
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 218;
	
	  ;% bms_f4_P.nDLookupTable_tableData_aj
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 219;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ch
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 222;
	
	  ;% bms_f4_P.Gain_Gain_e
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 225;
	
	  ;% bms_f4_P.nDLookupTable_tableData_p
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 226;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_l
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 229;
	
	  ;% bms_f4_P.Gain_Gain_i
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 232;
	
	  ;% bms_f4_P.nDLookupTable_tableData_mk
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 233;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_gb
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 236;
	
	  ;% bms_f4_P.Gain_Gain_fu
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 239;
	
	  ;% bms_f4_P.nDLookupTable_tableData_o
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 240;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ll
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 243;
	
	  ;% bms_f4_P.Gain_Gain_b
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 246;
	
	  ;% bms_f4_P.nDLookupTable_tableData_o3
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 247;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_b
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 250;
	
	  ;% bms_f4_P.Gain_Gain_k
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 253;
	
	  ;% bms_f4_P.nDLookupTable_tableData_pv
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 254;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_f
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 257;
	
	  ;% bms_f4_P.Gain_Gain_bj
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 260;
	
	  ;% bms_f4_P.nDLookupTable_tableData_mx
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 261;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_hs
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 264;
	
	  ;% bms_f4_P.Gain_Gain_bi
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 267;
	
	  ;% bms_f4_P.nDLookupTable_tableData_b
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 268;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_f4
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 271;
	
	  ;% bms_f4_P.Gain_Gain_ix
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 274;
	
	  ;% bms_f4_P.nDLookupTable_tableData_lf
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 275;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ky
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 278;
	
	  ;% bms_f4_P.Gain_Gain_dp
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 281;
	
	  ;% bms_f4_P.nDLookupTable_tableData_k
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 282;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ot
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 285;
	
	  ;% bms_f4_P.Gain_Gain_kc
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 288;
	
	  ;% bms_f4_P.nDLookupTable_tableData_o2
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 289;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_bp
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 292;
	
	  ;% bms_f4_P.Gain_Gain_ek
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 295;
	
	  ;% bms_f4_P.nDLookupTable_tableData_n
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 296;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_d
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 299;
	
	  ;% bms_f4_P.Gain_Gain_pp
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 302;
	
	  ;% bms_f4_P.nDLookupTable_tableData_bj
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 303;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_iz
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 306;
	
	  ;% bms_f4_P.Gain_Gain_oh
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 309;
	
	  ;% bms_f4_P.nDLookupTable_tableData_oo
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 310;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ow
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 313;
	
	  ;% bms_f4_P.Gain_Gain_pe
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 316;
	
	  ;% bms_f4_P.nDLookupTable_tableData_aa
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 317;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_ko
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 320;
	
	  ;% bms_f4_P.Gain_Gain_g
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 323;
	
	  ;% bms_f4_P.nDLookupTable_tableData_d
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 324;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_lc
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 327;
	
	  ;% bms_f4_P.Gain_Gain_cn
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 330;
	
	  ;% bms_f4_P.nDLookupTable_tableData_f0
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 331;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_mh
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 334;
	
	  ;% bms_f4_P.Gain_Gain_j
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 337;
	
	  ;% bms_f4_P.nDLookupTable_tableData_hk
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 338;
	
	  ;% bms_f4_P.nDLookupTable_bp01Data_d4
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 341;
	
	  ;% bms_f4_P.Gain_Gain_oa
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 344;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (bms_f4_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% bms_f4_B.Selector
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_B.Selector1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 10;
	
	  ;% bms_f4_B.Selector2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 20;
	
	  ;% bms_f4_B.Min3
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 30;
	
	  ;% bms_f4_B.Min4
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 31;
	
	  ;% bms_f4_B.VectorConcatenate1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 32;
	
	  ;% bms_f4_B.VectorConcatenate
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 35;
	
	  ;% bms_f4_B.VectorConcatenate2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 37;
	
	  ;% bms_f4_B.VectorConcatenate3
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 39;
	
	  ;% bms_f4_B.VectorConcatenate_k
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_B.MatrixConcatenate
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_B.VectorConcatenate1_a
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 16;
    sectIdxOffset = 3;
    
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
    ;% Auto data (bms_f4_DW)
    ;%
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% bms_f4_DW.is_c1_bms_f4
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.temporalCounter_i1
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.is_active_c1_bms_f4
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% bms_f4_DW.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.isNotInit
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart3.sfEvent
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart3.is_c2_bms_f4
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.sf_Chart3.is_ON
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bms_f4_DW.sf_Chart3.temporalCounter_i1
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart3.is_active_c2_bms_f4
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart3.flagBalancingDone
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart2.sfEvent
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart2.is_c2_bms_f4
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.sf_Chart2.is_ON
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bms_f4_DW.sf_Chart2.temporalCounter_i1
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart2.is_active_c2_bms_f4
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart2.flagBalancingDone
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart1.sfEvent
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart1.is_c2_bms_f4
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bms_f4_DW.sf_Chart1.is_ON
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bms_f4_DW.sf_Chart1.temporalCounter_i1
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart1.is_active_c2_bms_f4
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bms_f4_DW.sf_Chart1.flagBalancingDone
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
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


  targMap.checksum0 = 1108870111;
  targMap.checksum1 = 397091239;
  targMap.checksum2 = 995758487;
  targMap.checksum3 = 1004638080;

