%Contactor Resistance
ContactorChargerRes = 0.01;
ContactorInverterRes = 0.01;
ContactorCommonRes = 0.01;

%Relay Resistance
RelayPreChargerRes = 0.01;
RelayPreInverterRes = 0.01;

RelayDisChargerRes = 0.01;
RelayDisInverterRes = 0.01;

%Pre-charge Resistances
PreChargerRes = 1000;
PreInverterRes = 1000;
%Discharge Resistance
DisChargerRes = 250;
DisInverterRes = 250;

%FSM Constants
VbattThersholdChrg = 0.8; %[%]
VbattThresholdDis = 0.2;
VbattMin = 1; %[Volt]
DrivetrainEnDelay = 0.1; %[second]




