%% Cells custom parameters
CellThermalMass = 5000;
%CellThermalMass = 527.6215; 30000

CellNumberForSegment = 10;
SegmentNumber = 3;

%% Thermal parameters
AmbientTemperature = 25; %Ambient temperature [degC]

Cell2CellConductiveArea = 1e-2;
Cell2CellConductiveThickness = 0.1;
Cell2CellConductiveThermConduct = 401;

UpperSegmentConductiveArea = 0;
UpperSegmentConductiveThickness = 0;
UpperSegmentConductiveThermConduct = 0;

LowerSegmentConductiveArea = 1e-2;
LowerSegmentConductiveThickness = 2;
LowerSegmentConductiveThermConduct = 401;

UpperSegment2CaseConductiveArea = 0;
UpperSegment2CaseConductiveThickness = 0;
UpperSegment2CaseConductiveThermConduct = 0;

LowerSegment2CaseConductiveArea = 0;
LowerSegment2CaseConductiveThickness = 0;
LowerSegment2CaseConductiveThermConduct = 0;

%% Balancing circuit parameters
PassiveBalancingRes(1) = 10;
PassiveBalancingRes(2) = 10;
PassiveBalancingRes(3) = 10;
PassiveBalancingRes(4) = 10;
PassiveBalancingRes(5) = 10;
PassiveBalancingRes(6) = 10;
PassiveBalancingRes(7) = 10;
PassiveBalancingRes(8) = 10;
PassiveBalancingRes(9) = 10;
PassiveBalancingRes(10) = 10;

%% Battery pack busbar resistance
BusbarRes(1) = 0.05; %[Ohm]
BusbarRes(2) = 0.05; %[Ohm]
BusbarRes(3) = 0.05; %[Ohm]
BusbarRes(4) = 0.05; %[Ohm]

%% SOC parameters
SOCInit = 0.95;
Ts = 0.01;
LUTBattery_Charge = [2.41,2.39,2.3];
LUTBattery_Charge_Temp = [278.1499938964844,293.1499938964844,323.1499938964844];
