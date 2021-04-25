%% Cells custom parameters
CellThermalMass = 30000;
%CellThermalMass = 527.6215;

CellNumberForSegment = 10;
SegmentNumber = 10;

CellResDeltaMin = 0.001; % Minimum resistance delta between cells [Ohm]
CellResDeltaMax = 0.002; % Maximum resistance delta between cells [Ohm]

%Generate additionl series resistance in every cell choosen as random
%number between 1 mOhm and 2 mOhm
for segment_index = 1 : SegmentNumber
    for cell_index = 1 : CellNumberForSegment
        CellSeriesRes(segment_index, cell_index) = CellResDeltaMin + rand(1,1)*(CellResDeltaMax - CellResDeltaMin);
    end
end


%% Thermal parameters
AmbientTemperature = 25 + 273.15; %Ambient temperature [K]

Cell2CellConductiveArea = 1e-2;
Cell2CellConductiveThickness = 2;
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
BusbarRes(5) = 0.05; %[Ohm]
BusbarRes(6) = 0.05; %[Ohm]
BusbarRes(7) = 0.05; %[Ohm]
BusbarRes(8) = 0.05; %[Ohm]
BusbarRes(9) = 0.05; %[Ohm]
BusbarRes(10) = 0.05; %[Ohm]
BusbarRes(11) = 0.05; %[Ohm]


