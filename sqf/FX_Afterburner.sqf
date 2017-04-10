
private ["_MaxIntensity","_maxspeed","_Boost","_leftengine","_rightengine","_emitters","_Intensity","_looptime", "_plane"];

        _plane = _this;
		_MaxIntensity = 1;
		_Boost = 0.6;
		_Intensity = 0.4;
		_maxspeed = getNumber (configFile >> "cfgVehicles" >> typeOf _plane >> "maxSpeed");
		 sleep 0.5;
		_leftengine = "#particlesource" createVehicle (_plane selectionPosition "EngineL");
		_rightengine = "#particlesource" createVehicle (_plane selectionPosition "EngineR");
		_emitters = [_leftengine,_rightengine];
		{
		 _x setParticleRandom [0.05,[0.05,0.05,0.05],[0.05,0.05,0.05],0,0.8,[0.1,0.1,0.1,0],0,0]
		} forEach _emitters;
		{
		 _x setDropInterval 0
		} forEach _emitters;

		_looptime = 0.1;
		_leftengine attachTo [_plane, [0,5,1], "EngineL"];
		_rightengine attachTo [_plane, [0,5,1], "EngineR"];
		while {(alive _plane)} do
		{
			if ((isEngineOn _plane) and ((_plane animationPhase "ABcut") < 0.3)) then
			{
			    _plane setObjectTexture [4, "\Su_47_Berkut\tex\LCD\engineoff.paa"];
				if (_Intensity < _MaxIntensity) then
				{
				    _Intensity = _Intensity + 0.1*(15*_looptime);
				 };
				if ((speed _plane) < _maxspeed) then
				{
				 _plane setVelocity [(velocity _plane select 0)+((vectorDir _plane) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 1)+((vectorDir _plane) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 2)+((vectorDir _plane) select 2)*((_Boost*_Intensity/2)*(15*_looptime))]
				};
				if (fuel _plane > 0) then {_plane setFuel ((fuel _plane)-((1/9000)*(3*_looptime)))};
			}
			else
			{
			    _plane setObjectTexture [4, "\Su_47_Berkut\tex\LCD\engineon.paa"];
				if (_Intensity > 0) then
				{
				 _Intensity = _Intensity - 0.2*(15*_looptime);
				};
			};

			_leftengine setParticleParams ["\Mikoyan-Mig-29\cl_exp","","Billboard",1,0.07,[0,-6.5,-0.9],[(velocity _plane select 0) - ((vectorDir _plane) select 0)*20,(velocity _plane select 1) - ((vectorDir _plane) select 1)*20,(velocity _plane select 2) - ((vectorDir _plane) select 2)*20],1,1.2745,1,0,[0.4+(2*(speed _plane/_maxspeed)),0.5+(10*(speed _plane/_maxspeed))],[[0.040,0.100,0.900,0.1500*_Intensity],[0.200,0.200,0.800,0.1000*_Intensity],[0.500,0.200,0.000,0.0250*_Intensity],[0.000,0.000,0.000,0.0000*_Intensity]],[0],0,0,"","",(_plane selectionPosition "EngineL")];
			_rightengine setParticleParams ["\Mikoyan-Mig-29\cl_exp","","Billboard",1,0.07,[0,-6.5,-0.9],[(velocity _plane select 0) - ((vectorDir _plane) select 0)*20,(velocity _plane select 1) - ((vectorDir _plane) select 1)*20,(velocity _plane select 2) - ((vectorDir _plane) select 2)*20],1,1.2745,1,0,[0.4+(2*(speed _plane/_maxspeed)),0.5+(10*(speed _plane/_maxspeed))],[[0.040,0.100,0.900,0.1500*_Intensity],[0.200,0.200,0.800,0.1000*_Intensity],[0.500,0.200,0.000,0.0250*_Intensity],[0.000,0.000,0.000,0.0000*_Intensity]],[0],0,0,"","",(_plane selectionPosition "EngineR")];

			if (_Intensity > 0) then
			{
			 {
			  _x setDropInterval 0.001
			 } forEach _emitters
			}
			else
			{
			 {
			  _x setDropInterval 0
			 } forEach _emitters
			};
			sleep 0.05;
		};
		{
		 deleteVehicle _x
		} forEach _emitters;
		sleep 3;