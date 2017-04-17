class CfgVehicles
{
	  class All{};
		class O_Pilot_F;
		class AllVehicles: All{};
		class Air: AllVehicles{};
		class Plane: Air
		{
			class NewTurret;
			class ViewPilot;
			class Sounds;
			class AnimationSources;
			class Eventhandlers;
		};
	class Su_47_Berkut: Plane
	{
		side = 0;
		faction = "OPF_F";
		crew = "O_Pilot_F";
		author="Nobatgeldi Geldimammedov";
		displayName="Sukhoi Su-47 Berkut";
		model="\Su_47_Berkut\Su_47_Berkut.p3d";
		driverAction="su47_pilot";
		driverCanSee = 1+2+4+8+16;
		getInAction = "";
		animated=1;
		vehicleClass="Air";
		icon="\Mikoyan-Mig-29\tex\icon.paa";
		picture="\Mikoyan-Mig-29\tex\pic.paa";
		unitInfoType="RscOptics_CAS_Pilot";
		driverWeaponsInfoType = "RscOptics_CAS_01_TGP";
		simulation="airplane";
		_generalMacro="Su_47_Berkut";
		scope=2;
		accuracy = 3.500000;
		nameSound="aircraft";
		fuelCapacity=1500;
		maxSpeed = 2500;
		camouflage=5;
		lightOnGear = true;
		Audible=9;
		mapSize=20;
		MapUseRealSize = true;
		cost=1000000;
		type=2;
		threat[]={0.99999999,0.99999999,1};
		armor=80;
		damageResistance=0.00336;
		armorStructured=1;
		incomingMissileDetectionSystem=16;
		radarType=4;
		// Vehicle/turret setting. Displays all targets known to vehicle sensors in via the ingame UI. Values can be combined.
		showAllTargets = 2; //LockYes, show targets from all sensors
		//Vehicle/turret setting. Displays gunner/commander turret aimpoints on the HUD.
		showCrewAim = 1+2+4; // values can be combined
		radarRange = 150000;
		laserScanner=1;
		irTarget=1;
		irScanRangeMin=100;
		irScanRangeMax=10000;
		irScanToEyeFactor=4;
		irScanGround=1;
		nvTarget = 1;
		nvScanner = 1;
		LockDetectionSystem="1 + 2 + 4 + 8";
		landingAoa="rad 10";
		sweepDisengageRandomCourseCoef = 1;
		landingSpeed=180;
		enableGPS = 1;
		fuelLeakiness = 20;
		extCameraPosition[] = {0, 2, -30};
		gearRetracting=1;
		//timeToStop=0.2;
		commanderUsesPilotView=true;
		flapsFrictionCoef=0.2;
		forceThrustMultiple = 2.0;
		flyInHeight=200;
		supplyRadius=13;
		airBrake = true;
		maxRotationX=10.5;
	    //secondaryExplosion = true;
		turnCoef=5.0;
		damping=40;
		damperSize = 0.12;
		wheelWeight = 175;
		memoryPointMissile[] =
		{
		};
		memoryPointGun="machine_gun";
		driverRightHandAnimName = "ControlStick";
		/*memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		driverLeftHandAnimName = "control_throttle";
		driverLeftLegAnimName = "pilot_pedal_L";
		driverRightLegAnimName = "pilot_pedal_R";
		memoryPointLDust = "pos_dust_left";
		memoryPointRDust = "pos_dust_right";
		memoryPointGun = "pos_nosegun";
		memoryPointLMissile = "LMissile";
		memoryPointRMissile = "RMissile";*/
		memoryPointCM[] = {"flare_L","flare_R"};
		memoryPointCMDir[] = {"flare_L_dir","flare_R_dir"};
		memoryPointsGetInDriver = "get_in";
		//memoryPointsGetInDriverDir = "pos_driver_dir";

		weapons[]=
		{
            "Mig_GSh301",

            "Su47_R73M1Launcher",

            "CMFlareLauncher"
		};
		magazines[]=
		{
            "Mig_150Rnd_30mm_GSh301",

            "Su47_R73M1",
            "Su47_R73M1",
            "Su47_R73M1",
            "Su47_R73M1",

            "300Rnd_CMFlare_Chaff_Magazine"
		};
		class pilotCamera {
			class OpticsIn {
				class Wide {
					opticsDisplayName = WFOV;
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = (30 / 120);
					minFov = (30 / 120);
					maxFov = (30 / 120);
					directionStabilized = 1;
					visionMode[] = {"Normal", "Ti"};
					thermalMode[] = {0, 1};
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
				};

				class Medium : Wide {
					opticsDisplayName = MFOV;
					initFov = (15 / 120);
					minFov = (15 / 120);
					maxFov = (15 / 120);
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};

				class Narrow : Wide {
					opticsDisplayName = NFOV;
					initFov = (3.75 / 120);
					minFov = (3.75 / 120);
					maxFov = (3.75 / 120);
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
				showMiniMapInOptics = 1;
				showUAVViewInOptics = 0;
				showSlingLoadManagerInOptics = 0;
			};
			minTurn = -180;
			maxTurn = 180;
			initTurn = 0;
			minElev = -10;
			maxElev = 90;
			initElev = 0;
			maxXRotSpeed = 0.3;
			maxYRotSpeed = 0.3;
			pilotOpticsShowCursor = 1;
			controllable = 1;
		};
		memoryPointDriverOptics = "gear_light_dir";
		rudderInfluence = 0.2;
		aileronSensitivity=2.5;
		elevatorSensitivity=2.9;
		radarTargetSize=1.0;					/*Radar cross-section coefficient of the vehicle. Works as a coefficient of
						                      RADAR Sensor's range within the given combat situation.
																	Early test values
																	0.1 - fully stealth (<0.0005m2 RCS) (not recommended)
																	0.7 - small aircrafts, semi-stealth (~1m2 RCS)
																	1.0 - mid sized aircraft, car (~5m2 RCS)
																	1.2 - tanks, trucks (~10m2 RCS)
																	2.0 - large bomber, small ship and bigger (>80m2 RCS)*/
		receiveRemoteTargets = true; //if the vehicle is able to receive targets
																 //  and positions from friendly vehicles with reportRemoteTargets.

		reportRemoteTargets = true;  /* Says if the vehicle is able to broadcast targets acquired by own sensors*/
		reportOwnPosition = true; 	/*Says if the vehicle is able to broadcast its own position*/
        /// envelope defines lift produced by the shape of the plane according to current speed relative to maxSpeed
		/// the first element of the array is for zero speed, the last for 125 % of maxSpeed, the rest in between is evenly distributed
		/// there may be as many elements as you wish, using 13 should be preferred as it modulates the 10% increase with reasonable error
		///			  0%   10%   20%   30%   40%   50%   60%   70%   80%   90%   100%  110%  125%
	    //envelope[] = {0.0, 0.50, 1.0, 2.00, 7.00, 7.00, 7.00, 6.85, 6.50, 5.80, 4.60, 2.80, 0.00};
		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};
		/// forces keeping plane aligned with its speed direction - the bigger force the better it changes the direction of flight
        //draconicForceXCoef = 7; //left/right
        //draconicForceYCoef = 1.5; //up/down
        //draconicForceZCoef = 0.5; // forward/back
        //draconicTorqueXCoef = 1.2; //0.15
        //draconicTorqueYCoef = 1; // noseup/down twist torque

        /// rudder, elevator, aileron, thrust effectiveness; if empty old settings is used
        // effectiveness according to current speed and maxSpeed ratio
        // last value goes for 150% of max speed
        //				  0%   10%  20%  30%  40%  50%  60%  70%  80%  90%  100% 110% 120% 130% 140% 150%
        //thrustCoef[] =	{ 1.0, 1.4, 1.5, 1.5, 1.5, 1.4, 1.3, 1.2, 1.2, 1.0, 0.9, 0.7, 0.4, 0.3, 0.0, 0.0 };
        //elevatorCoef[]= { 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; //default value is 1
        //aileronCoef[]=	{   1, 1.5,   2, 2.5,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   1,   1 };  //default value is 1
        //rudderCoef[] = {};   //default value is fabs(speed.Z())*InvSqrt(Square(speed.X())+Square(speed.Z()));

		class MarkerLights
		{
			class Cockpit_light_1
			{
				name="pos driver";
				ambient[]={0.0099999998,0.0099999998,0.0099999998,1};
				color[]={0.029999999,1,0.11,1};
				brightness=0.05;
				blinking=0;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};
			/*class back_lights
			{
				name="back_lights";
				color[]={0.0, 0.9, 1.0, 0.0};
				ambient[]={0.0, 0.0, 0.0, 0.0};
				brightness=0.05;
				blinking=true;
			};
			class hull_lights
			{
				name="hull_lights";
				color[]={0.0, 0.9, 1.0, 0.0};
				ambient[]={0.0, 0.0, 0.0, 0.0};
				brightness=0.05;
				blinking=false;
			};
			class wing_lights
			{
				name="wing_lights";
				color[]={0.0, 0.9, 1.0, 0.0};
				ambient[]={0.0, 0.0, 0.0, 0.0};
				brightness=0.05;
				blinking=false;
			};*/
		};
		class Reflectors
		{
			class Left
 			{
 				color[]={7000,7500,10000,1};
 				ambient[]={100,100,100,0};
 				position="gear_light";
 				direction="gear_light_dir";
 				hitpoint="L svetlo";
 				selection="L svetlo";
 				size=1;
 				innerAngle=20;
 				outerAngle=60;
 				coneFadeCoef=10;
 				intensity=50;
 				useFlare=1;
 				dayLight=0;
 				FlareSize=4;
 				class Attenuation
 				{
 					start=1;
 					constant=0;
 					linear=0;
 					quadratic=4;
 				};
 			};
		};
		class Exhausts
		{
			class Exhaust_left
			{
				position="EngineL";
				direction="left_dir";
				effect="ExhaustsEffectPlane";
			};
			class Exhaust_right
			{
				position="EngineR";
				direction="right_dir";
				effect="ExhaustsEffectPlane";
			};
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\ext-jetair-engine-low1",
					2.5118899,
					1,
					1600
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\ext-jetair-engine-high3",
					2.5118899,
					1.3,
					1800
				};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\ext-jetair-forsage1",
					2.5118899,
					1.1,
					2000
				};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[] = {3.14, 3.92, 2.0, 0.5};
			};
			class WindNoiseOut
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\noise", 0.562341, 1.0, 150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\int-av8b-engine-low",
					0.56234097,
					1
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\int-av8b-engine",
					1,
					1
				};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageIn
			{
				sound[]=
				{
					"Mikoyan-Mig-29\sounds\int-av8b-forsage-1",
					0.56234097,
					1.1
				};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					0.70794576,
					1
				};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
			class RainExt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.77828, 1.0, 100};
				frequency = 1;
				volume = "camPos * rain * (speed factor[50, 0])";
			};

			class RainInt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_int", 1.0, 1.0, 100};
				frequency = 1;
				volume = "(1-camPos) * rain * (speed factor[50, 0])";
			};
		};
		/*class RenderTargets
		{
			class Center_Pilot_Mirror
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="PIP_mirror_c";
					pointDirection="PIP_mirror_c_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
			class Left_Pilot_Mirror
			{
				renderTarget="rendertarget1";
				class CameraView1
				{
					pointPosition="PIP_mirror_l";
					pointDirection="PIP_mirror_l_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
			class Right_Pilot_Mirror
			{
				renderTarget="rendertarget2";
				class CameraView1
				{
					pointPosition="PIP_mirror_r";
					pointDirection="PIP_mirror_r_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
		};*/
		attenuationEffectType = "PlaneAttenuation";
		soundGetIn[] = {"A3\Sounds_F_EPC\CAS_02\TO_getin", 1.0, 1};
		soundGetOut[] = {"A3\Sounds_F_EPC\CAS_02\getout", 1.0, 1, 40};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_int", 0.794328, 1.0};
		soundEngineOnExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_ext", 1.0, 1.0, 500};
		soundEngineOffInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_int", 0.794328, 1.0};
		soundEngineOffExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_ext", 1.0, 1.0, 500};
		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", 0.316228, 1};
		soundIncommingMissile[] = {"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4", 0.398107, 1.0};
		soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.0, 150};
		soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.0, 150};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.0, 100};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.0, 100};
		class scrubLandInt {
			sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", 1.0, 1.0, 100};
			frequency = 1;
			volume = "(scrubLand factor[0.01, 0.20])";
		};
		insideSoundCoef = 0.1;
		hiddenselections[]=
		{
			"R_73_m1",
			"R_73_m2",
			"R_73_m3",
			"R_73_m4",
			"engine_on_LCD",
			"schema_LCD"
		};
		class AnimationSources
		{
		  class gsh_301_count
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class ABcut
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
		  class LCD_control
		    {
		        source = "user";
		        initPhase = 1;
		        animPeriod = 1;
		    };
			class R_73_m1
		    {
		        source = "user";
		        initPhase = 1;
		        animPeriod = 1;
		    };
			class R_73_m2
		    {
		        source = "user";
		        initPhase = 1;
		        animPeriod = 1;
		    };
			class R_73_m3
		    {
		        source = "user";
		        initPhase = 1;
		        animPeriod = 1;
		    };
			class R_73_m4
		    {
		        source = "user";
		        initPhase = 1;
		        animPeriod = 1;
		    };
		    class missile
            {
            	source="user";
            	initPhase=1;
            	animPeriod=2;
            };
            class safe_mod
            {
                source="user";
                initPhase=1;
                animPeriod=0.0099999998;
            };
		};
		class UserActions
		{
		  /*class Super_M_on
      {
        		displayName="Missile ON";
        		position="pos driver";
        		radius=20;
        		onlyforplayer=0;
        		condition="this animationPhase ""Abcut"" == 1 and player in this and isengineon this";
        		statement="this animate [""Abcut"",0]";
        		hideOnUse=1;
        		showWindow=0;
      };
      class Super_M_off
      {
               displayName="Missile OFF";
               position="pos player";
               radius=20;
               onlyforplayer=0;
               condition="this animationPhase ""Abcut"" == 0 and player in this and isengineon this";
               statement="this animate [""Abcut"",1]";
               hideOnUse=1;
               showWindow=0;
      };*/
			class ABon
			{
				displayName="Afterburner ON";
				position="pos player";
				shortcut="SeagullFastForward";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 1 and player in this and isengineon this";
				statement="this animate [""ABcut"",0]";
				hideOnUse=1;
				showWindow=0;
			};
			class ABoff
			{
				displayName="Afterburner Off";
				position="pos player";
				shortcut="SeagullFastForward";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 0 and player in this and isengineon this";
				statement="this animate [""ABcut"",1]";
				showWindow=0;
				hideOnUse=1;
			};
		};
		class WingVortices
        {
        			class WingTipLeft
        			{
        				effectName = "WingVortices";// name of the effect
        				position = "body_vapour_L_E"; // name of the memory point in model
        			};
        			class WingTipRight
        			{
        				effectName = "WingVortices"; // name of the effect
        				position = "body_vapour_R_E";// name of the memory point in model
        			};
                    /*class BodyLeft
                    {
                            effectName = "OK_F_35C_BodyVortices";// name of the effect
                            position = "body_vapour_L_S"; // name of the memory point in model
                    };

                    class BodyRight
                    {
                            effectName = "OK_F_35C_BodyVortices"; // name of the effect
                            position = "body_vapour_R_S";// name of the memory point in model
                    };*/
        };
		class Eventhandlers: Eventhandlers
		{
			init   = "[_this select 0] execVM ""\Su_47_Berkut\sqf\init.sqf"",";
			fired  = "[_this] execVM ""\Su_47_Berkut\sqf\fire.sqf"",";
			gear   = "[_this] execVM ""\Su_47_Berkut\sqf\gear_lcd.sqf"",";
			engine = "[_this] execVM ""\Su_47_Berkut\sqf\engine.sqf"",";
		};
		class Library
		{
			libTextDesc = "The Sukhoi Su-47 Berkut, also designated S-32 and S-37 during initial development, was an experimental supersonic jet fighter developed by Sukhoi Aviation Corporation.";
		};
		//HUD configuration
			class MFD
			{
			    /*class HUD_statick_LCD
            	{
            		topLeft="HUD_TOP_L_LCD";
            		topRight="HUD_TOP_R_LCD";
            		bottomLeft="HUD_BOT_L_LCD";
            		borderLeft=0;
            		borderRight=0;
            		borderTop=0;
            		borderBottom=0;
            		color[]={0,1,0,1};
            		enableParallax=0;
            		class Bones
                    {
                        class WeaponAim
						{
							type="vector";
							source="weapon";
							pos0[]={0.5,0.55500001};
							pos10[]={1.5,1.5549999};
						};
                    };
                    class Draw
					{
						color[]={0,1,0,1};
						alpha=1;
						condition="on";
                        class WeaponName
						{
							type="text";
							source="weapon";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
                            {

                            									{
                            										0.029999999,
                            										"0.53 - 0.045"
                            									},
                            									1
                            								};
                            right[]=
                            {

                            									{
                            										0.079999998,
                            										"0.53 - 0.045"
                            									},
                            									1
                            								};
                            down[]=
                            {

                            									{
                            										0.029999999,
                            										"0.53 - 0.005"
                            									},
                            									1
                            								};
						};
						class AmmoCount
						{
							type="text";
							source="ammo";
							sourceScale=1;
							align="right";
							scale=1;
                            pos[]=
							{

									{
										0.029999999,
										"0.53 + 0.005"
									},
									1
								};
							right[]=
							{

									{
										0.079999998,
										"0.53 + 0.005"
									},
									1
								};
							down[]=
							{

									{
										0.029999999,
										"0.53 + 0.045"
									},
									1
								};
						};
					};
            	};*/
				class HUD_HMD
				{
					topLeft="HUD_TOP_L";
					topRight="HUD_TOP_R";
					bottomLeft="HUD_BOT_L";
					borderLeft=0;
					borderRight=0;
					borderTop=0;
					borderBottom=0;
					color[]={0,1,0,1};
					enableParallax=0;
					class Bones
					{
						class WeaponAim
						{
							type="vector";
							source="weapon";
							pos0[]={0.5,0.55500001};
							pos10[]={1.5,1.5549999};
						};
					};
					class Draw
					{
						color[]={0,1,0,1};
						alpha=0.5;
						condition="on";
						class StallGroup
						{
							type="group";
							condition="stall";
							color[]={1,0,0};
							class StallText
							{
								type="text";
								source="static";
								text="STALL";
								align="center";
								scale=1;
								pos[]=
								{

									{
										0.5,
										"0.53 - 0.25"
									},
									1
								};
								right[]=
								{

									{
										0.55000001,
										"0.53 - 0.25"
									},
									1
								};
								down[]=
								{

									{
										0.5,
										"0.53 - 0.17"
									},
									1
								};
							};
						};
						class AAMissile
						{
							type="group";
							condition="AAmissile";
							class AAMissileCrosshair
							{
								type="line";
								width=4;
								points[]=
								{

									{
										"WeaponAim",
										{0,-0.25},
										1
									},

									{
										"WeaponAim",
										{0.043400001,-0.2462},
										1
									},

									{
										"WeaponAim",
										{0.085500002,-0.234925},
										1
									},

									{
										"WeaponAim",
										{0.125,-0.2165},
										1
									},

									{
										"WeaponAim",
										{0.16069999,-0.19149999},
										1
									},

									{
										"WeaponAim",
										{0.19149999,-0.16069999},
										1
									},

									{
										"WeaponAim",
										{0.2165,-0.125},
										1
									},

									{
										"WeaponAim",
										{0.234925,-0.085500002},
										1
									},

									{
										"WeaponAim",
										{0.2462,-0.043400001},
										1
									},

									{
										"WeaponAim",
										{0.25,0},
										1
									},

									{
										"WeaponAim",
										{0.2462,0.043400001},
										1
									},

									{
										"WeaponAim",
										{0.234925,0.085500002},
										1
									},

									{
										"WeaponAim",
										{0.2165,0.125},
										1
									},

									{
										"WeaponAim",
										{0.19149999,0.16069999},
										1
									},

									{
										"WeaponAim",
										{0.16069999,0.19149999},
										1
									},

									{
										"WeaponAim",
										{0.125,0.2165},
										1
									},

									{
										"WeaponAim",
										{0.085500002,0.234925},
										1
									},

									{
										"WeaponAim",
										{0.043400001,0.2462},
										1
									},

									{
										"WeaponAim",
										{0,0.25},
										1
									},

									{
										"WeaponAim",
										{-0.043400001,0.2462},
										1
									},

									{
										"WeaponAim",
										{-0.085500002,0.234925},
										1
									},

									{
										"WeaponAim",
										{-0.125,0.2165},
										1
									},

									{
										"WeaponAim",
										{-0.16069999,0.19149999},
										1
									},

									{
										"WeaponAim",
										{-0.19149999,0.16069999},
										1
									},

									{
										"WeaponAim",
										{-0.2165,0.125},
										1
									},

									{
										"WeaponAim",
										{-0.234925,0.085500002},
										1
									},

									{
										"WeaponAim",
										{-0.2462,0.043400001},
										1
									},

									{
										"WeaponAim",
										{-0.25,0},
										1
									},

									{
										"WeaponAim",
										{-0.2462,-0.043400001},
										1
									},

									{
										"WeaponAim",
										{-0.234925,-0.085500002},
										1
									},

									{
										"WeaponAim",
										{-0.2165,-0.125},
										1
									},

									{
										"WeaponAim",
										{-0.19149999,-0.16069999},
										1
									},

									{
										"WeaponAim",
										{-0.16069999,-0.19149999},
										1
									},

									{
										"WeaponAim",
										{-0.125,-0.2165},
										1
									},

									{
										"WeaponAim",
										{-0.085500002,-0.234925},
										1
									},

									{
										"WeaponAim",
										{-0.043400001,-0.2462},
										1
									},

									{
										"WeaponAim",
										{0,-0.25},
										1
									}
								};
							};
						};
						class ATMissile
						{
							condition="ATmissile";
							type="group";
							class ATMissileCrosshair
							{
								type="line";
								width=4;
								points[]=
								{

									{
										"WeaponAim",
										{-0.15000001,-0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											-0.15000001,
											"-0.15 + 0.02"
										},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.15000001,0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											-0.15000001,
											"0.15 - 0.02"
										},
										1
									},
									{},

									{
										"WeaponAim",
										{0.15000001,-0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											0.15000001,
											"-0.15 + 0.02"
										},
										1
									},
									{},

									{
										"WeaponAim",
										{0.15000001,0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											0.15000001,
											"0.15 - 0.02"
										},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.15000001,-0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											"-0.15 + 0.02",
											-0.15000001
										},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.15000001,0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											"-0.15 + 0.02",
											0.15000001
										},
										1
									},
									{},

									{
										"WeaponAim",
										{0.15000001,-0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											"0.15 - 0.02",
											-0.15000001
										},
										1
									},
									{},

									{
										"WeaponAim",
										{0.15000001,0.15000001},
										1
									},

									{
										"WeaponAim",

										{
											"0.15 - 0.02",
											0.15000001
										},
										1
									}
								};
							};
						};
					};
					helmetMountedDisplay = 1;
					helmetPosition[] = {-0.04, 0.04, 0.1};
					helmetRight[] = {0.08, 0, 0};
					helmetDown[] = {0, -0.08, 0};
				};
				class HUD_statick
				{
					topLeft="HUD_TOP_L";
					topRight="HUD_TOP_R";
					bottomLeft="HUD_BOT_L";
					borderLeft=0;
					borderRight=0;
					borderTop=0;
					borderBottom=0;
					color[]={0,1,0,1};
					enableParallax=0;
					class Bones
					{
						class PlaneOrientation
						{
							type="fixed";
							pos[]={0.5,0.52999997};
						};
						class WeaponAim
						{
							type="vector";
							source="weapon";
							pos0[]={0.5,0.55500001};
							pos10[]={1.5,1.5549999};
						};
						class Velocity
						{
							type="vector";
							source="velocity";
							pos0[]={0.5,0.52999997};
							pos10[]={1.5,1.53};
							angle=-2.3;
						};
						class Level0
						{
							type="horizon";
							pos0[]={0.5,0.52999997};
							pos10[]={1.5,1.53};
							angle=-2.3;
						};
					};
					class Draw
					{
						color[]={0,1,0,1};
						alpha=1;
						condition="on";
						class Horizont
						{
							clipTL[]={0.25,0.25};
							clipBR[]={0.75,0.75};
							class Dimmed
							{
								class Level00
								{
									type="line";
									width=15;
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"0 * 1.4"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"0 * 1.4"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"-0.045 * 1.4",
												"0 * 1.4"
											},
											1
										},

										{
											"Level0",

											{
												"-0.005 * 1.4",
												"0 * 1.4"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"0.005 * 1.4",
												"0 * 1.4"
											},
											1
										},

										{
											"Level0",

											{
												"0.045 * 1.4",
												"0 * 1.4"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"0.125 * 1.4",
												"0 * 1.4"
											},
											1
										},

										{
											"Level0",

											{
												"0.200 * 1.4",
												"0 * 1.4"
											},
											1
										}
									};
								};
								class Level2M5: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 5"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 5"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 5"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 5"
											},
											1
										}
									};
								};
								class Level2P5: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 5"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 5"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 5"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 5"
											},
											1
										}
									};
								};
								class Level2M10: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 10"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 10"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 10"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 10"
											},
											1
										}
									};
								};
								class Level2P10: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 10"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 10"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 10"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 10"
											},
											1
										}
									};
								};
								class Level2M15: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 15"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 15"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 15"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 15"
											},
											1
										}
									};
								};
								class Level2P15: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 15"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 15"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 15"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 15"
											},
											1
										}
									};
								};
								class Level2P20: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 20"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 20"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 20"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 20"
											},
											1
										}
									};
								};
								class Level2M20: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 20"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 20"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 20"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 20"
											},
											1
										}
									};
								};
								class Level2P30: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 30"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 30"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 30"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 30"
											},
											1
										}
									};
								};
								class Level2M30: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 30"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 30"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 30"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 30"
											},
											1
										}
									};
								};
								class Level2P40: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 40"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 40"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 40"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 40"
											},
											1
										}
									};
								};
								class Level2M40: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 40"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 40"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 40"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 40"
											},
											1
										}
									};
								};
								class Level2P50: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 50"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 50"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 50"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 50"
											},
											1
										}
									};
								};
								class Level2M50: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 50"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 50"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 50"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 50"
											},
											1
										}
									};
								};
								class Level2P60: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 60"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 60"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 60"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 60"
											},
											1
										}
									};
								};
								class Level2M60: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 60"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 60"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 60"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 60"
											},
											1
										}
									};
								};
								class Level2P70: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 70"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 70"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 70"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 70"
											},
											1
										}
									};
								};
								class Level2M70: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 70"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 70"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 70"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 70"
											},
											1
										}
									};
								};
								class Level2P80: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 80"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 80"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 80"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 80"
											},
											1
										}
									};
								};
								class Level2M80: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 80"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 80"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 80"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 80"
											},
											1
										}
									};
								};
								class Level2P90: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"+1.0 / 10 * 90"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"+1.0 / 10 * 90"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"+1.0 / 10 * 90"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"+1.0 / 10 * 90"
											},
											1
										}
									};
								};
								class Level2M90: Level00
								{
									type="line";
									points[]=
									{

										{
											"Level0",

											{
												"-0.200 * 1.4",
												"-1.0 / 10 * 90"
											},
											1
										},

										{
											"Level0",

											{
												"-0.125 * 1.4",
												"-1.0 / 10 * 90"
											},
											1
										},
										{},

										{
											"Level0",

											{
												"+0.125 * 1.4",
												"-1.0 / 10 * 90"
											},
											1
										},

										{
											"Level0",

											{
												"+0.200 * 1.4",
												"-1.0 / 10 * 90"
											},
											1
										}
									};
								};
							};
						};
						class PlaneOrientation_MiniPlane
						{
							width=20;
							type="line";
							points[]=
							{

								{
									"PlaneOrientation",
									{0.20999999,0},
									1
								},

								{
									"PlaneOrientation",
									1,
									{0.07,0},
									1
								},
								{},

								{
									"PlaneOrientation",
									1,
									{-0.20999999,0},
									1
								},

								{
									"PlaneOrientation",
									{-0.07,0},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0,0},
									1
								},

								{
									"PlaneOrientation",
									{0,-0.14},
									1
								}
							};
						};
						class PlaneOrientationLines
						{
							clipTL[]={0,0.1};
							clipBR[]={1,0};
							type="line";
							width=4;
							points[]=
							{

								{
									"PlaneOrientation",
									{-0.20999999,7.2250699e-009},
									1
								},

								{
									"PlaneOrientation",
									{-0.28,9.6334301e-009},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.20999999,-1.97107e-009},
									1
								},

								{
									"PlaneOrientation",
									{0.28,-2.62809e-009},
									1
								},
								{},

								{
									"PlaneOrientation",
									{-0.105,0.14314599},
									1
								},

								{
									"PlaneOrientation",
									{-0.14,0.190861},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.105,0.14314599},
									1
								},

								{
									"PlaneOrientation",
									{0.14,0.190861},
									1
								},
								{},

								{
									"PlaneOrientation",
									{-0.18186501,0.0826452},
									1
								},

								{
									"PlaneOrientation",
									{-0.242487,0.110194},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.18186501,0.0826452},
									1
								},

								{
									"PlaneOrientation",
									{0.242487,0.110194},
									1
								},
								{},

								{
									"PlaneOrientation",
									{-0.20284399,0.042780299},
									1
								},

								{
									"PlaneOrientation",
									{-0.270459,0.057040401},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.20284399,0.042780299},
									1
								},

								{
									"PlaneOrientation",
									{0.270459,0.057040401},
									1
								},
								{},

								{
									"PlaneOrientation",
									{-0.20920099,0.014406},
									1
								},

								{
									"PlaneOrientation",
									{-0.244068,0.016806999},
									1
								},
								{},

								{
									"PlaneOrientation",
									{-0.20681,0.028702401},
									1
								},

								{
									"PlaneOrientation",
									{-0.24127799,0.033486102},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.20681,0.028702401},
									1
								},

								{
									"PlaneOrientation",
									{0.24127799,0.033486102},
									1
								},
								{},

								{
									"PlaneOrientation",
									{0.20920099,0.014406},
									1
								},

								{
									"PlaneOrientation",
									{0.244068,0.016806999},
									1
								},
								{}
							};
						};
						class WeaponName
						{
							type="text";
							source="weapon";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.029999999,0.94},
								1
							};
							right[]=
							{
								{0.079999998,0.94},
								1
							};
							down[]=
							{
								{0.029999999,0.98000002},
								1
							};
						};
						class AmmoCount
						{
							type="text";
							source="ammo";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.029999999,0.88999999},
								1
							};
							right[]=
							{
								{0.079999998,0.88999999},
								1
							};
							down[]=
							{
								{0.029999999,0.93000001},
								1
							};
						};
						class FlapsGroup
						{
							type="group";
							condition="flaps";
							class FlapsText
							{
								type="text";
								source="static";
								text="FLAPS";
								align="right";
								scale=1;
								pos[]=
								{

									{
										0.029999999,
										"0.53 - 0.045"
									},
									1
								};
								right[]=
								{

									{
										0.079999998,
										"0.53 - 0.045"
									},
									1
								};
								down[]=
								{

									{
										0.029999999,
										"0.53 - 0.005"
									},
									1
								};
							};
						};
						class GearGroup
						{
							type="group";
							condition="ils";
							class GearText
							{
								type="text";
								source="static";
								text="GEAR";
								align="right";
								scale=1;
								pos[]=
								{

									{
										0.029999999,
										"0.53 + 0.005"
									},
									1
								};
								right[]=
								{

									{
										0.079999998,
										"0.53 + 0.005"
									},
									1
								};
								down[]=
								{

									{
										0.029999999,
										"0.53 + 0.045"
									},
									1
								};
							};
						};
						class LightsGroup
						{
							type="group";
							condition="lights";
							class LightsText
							{
								type="text";
								source="static";
								text="LIGHTS";
								align="right";
								scale=1;
								pos[]=
								{

									{
										0.029999999,
										"0.53 + 0.055"
									},
									1
								};
								right[]=
								{

									{
										0.079999998,
										"0.53 + 0.055"
									},
									1
								};
								down[]=
								{

									{
										0.029999999,
										"0.53 + 0.095"
									},
									1
								};
							};
						};
						class CollisionLightsGroup
						{
							type="group";
							condition="collisionlights";
							class CollisionLightsText
							{
								type="text";
								source="static";
								text="A-COL";
								align="right";
								scale=1;
								pos[]=
								{

									{
										0.029999999,
										"0.53 + 0.105"
									},
									1
								};
								right[]=
								{

									{
										0.079999998,
										"0.53 + 0.105"
									},
									1
								};
								down[]=
								{

									{
										0.029999999,
										"0.53 + 0.145"
									},
									1
								};
							};
						};
						class PitchNumber
						{
							type="text";
							source="horizonDive";
							sourceScale=57.295799;
							align="right";
							scale=1;
							pos[]=
							{
								{0.50999999,0.88999999},
								1
							};
							right[]=
							{
								{0.56,0.88999999},
								1
							};
							down[]=
							{
								{0.50999999,0.93000001},
								1
							};
						};
						class PitchText
						{
							type="text";
							source="static";
							text="PITCH";
							align="left";
							scale=1;
							pos[]=
							{
								{0.49000001,0.88999999},
								1
							};
							right[]=
							{
								{0.54000002,0.88999999},
								1
							};
							down[]=
							{
								{0.49000001,0.93000001},
								1
							};
						};
						class RollNumber
						{
							type="text";
							source="horizonBank";
							sourceScale=57.295799;
							align="right";
							scale=1;
							pos[]=
							{
								{0.50999999,0.83999997},
								1
							};
							right[]=
							{
								{0.56,0.83999997},
								1
							};
							down[]=
							{
								{0.50999999,0.88},
								1
							};
						};
						class RollText
						{
							type="text";
							source="static";
							text="ROLL";
							align="left";
							scale=1;
							pos[]=
							{
								{0.49000001,0.83999997},
								1
							};
							right[]=
							{
								{0.54000002,0.83999997},
								1
							};
							down[]=
							{
								{0.49000001,0.88},
								1
							};
						};
						class SpeedNumber
						{
							type="text";
							source="speed";
							sourceScale=3.5999999;
							align="right";
							scale=1;
							pos[]=
							{
								{0.13,0.14},
								1
							};
							right[]=
							{
								{0.18000001,0.14},
								1
							};
							down[]=
							{
								{0.13,0.18000001},
								1
							};
						};
						class SpeedText
						{
							type="text";
							source="static";
							text="SPD";
							align="left";
							scale=1;
							pos[]=
							{
								{0.11,0.14},
								1
							};
							right[]=
							{
								{0.16,0.14},
								1
							};
							down[]=
							{
								{0.11,0.18000001},
								1
							};
						};
						class AltitudeNumber
						{
							type="text";
							source="altitudeAGL";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.88999999,0.14},
								1
							};
							right[]=
							{
								{0.94,0.14},
								1
							};
							down[]=
							{
								{0.88999999,0.18000001},
								1
							};
						};
						class AltitudeText
						{
							type="text";
							source="static";
							text="AGL";
							align="left";
							scale=1;
							pos[]=
							{
								{0.87,0.14},
								1
							};
							right[]=
							{
								{0.92000002,0.14},
								1
							};
							down[]=
							{
								{0.87,0.18000001},
								1
							};
						};
						class AltitudeArrow
						{
							type="line";
							width=4;
							points[]=
							{

								{

									{
										"0.88 + 0.018",
										"0.40 - 0.016"
									},
									1
								},

								{
									{0.88,0.40000001},
									1
								},

								{

									{
										"0.88 + 0.018",
										"0.40 + 0.016"
									},
									1
								}
							};
						};
						class AltitudeLine
						{
							type="line";
							width=4;
							points[]=
							{

								{
									{0.87,0.60000002},
									1
								},

								{
									{0.87,0.2},
									1
								}
							};
						};
						class AltitudeScale
						{
							type="scale";
							horizontal=0;
							source="altitudeAGL";
							sourceScale=1;
							width=4;
							top=0.60000002;
							center=0.40000001;
							bottom=0.2;
							lineXleft=0.88;
							lineYright=0.88999999;
							lineXleftMajor=0.88;
							lineYrightMajor=0.89999998;
							majorLineEach=5;
							numberEach=5;
							step=20;
							stepSize="(0.60 - 0.20) / 15";
							align="right";
							scale=1;
							pos[]={0.91000003,0.57999998};
							right[]={0.95999998,0.57999998};
							down[]={0.91000003,0.62};
						};
						class ClimbNumber
						{
							type="text";
							source="vspeed";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.88999999,0.94},
								1
							};
							right[]=
							{
								{0.94,0.94},
								1
							};
							down[]=
							{
								{0.88999999,0.98000002},
								1
							};
						};
						class ClimbText
						{
							type="text";
							source="static";
							text="CLIMB";
							align="left";
							scale=1;
							pos[]=
							{
								{0.87,0.94},
								1
							};
							right[]=
							{
								{0.92000002,0.94},
								1
							};
							down[]=
							{
								{0.87,0.98000002},
								1
							};
						};
						class ClimbArrow
						{
							type="line";
							width=4;
							points[]=
							{

								{

									{
										"0.88 + 0.018",
										"0.80 - 0.016"
									},
									1
								},

								{
									{0.88,0.80000001},
									1
								},

								{

									{
										"0.88 + 0.018",
										"0.80 + 0.016"
									},
									1
								}
							};
						};
						class ClimbLine
						{
							type="line";
							width=4;
							points[]=
							{

								{
									{0.87,0.92500001},
									1
								},

								{
									{0.87,0.67500001},
									1
								}
							};
						};
						class ClimbScale
						{
							type="scale";
							horizontal=0;
							source="vspeed";
							sourceScale=1;
							width=4;
							top=0.92500001;
							center=0.80000001;
							bottom=0.67500001;
							lineXleft=0.88;
							lineYright=0.88999999;
							lineXleftMajor=0.88;
							lineYrightMajor=0.89999998;
							majorLineEach=2;
							numberEach=4;
							step=5;
							stepSize="(0.925 - 0.675) / 15";
							align="right";
							scale=1;
							pos[]={0.91000003,0.90499997};
							right[]={0.95999998,0.90499997};
							down[]={0.91000003,0.94499999};
						};
						class HeadingArrow
						{
							type="line";
							width=4;
							points[]=
							{

								{

									{
										"0.5 - 0.02",
										"0.11 - 0.02"
									},
									1
								},

								{
									{0.5,0.11},
									1
								},

								{

									{
										"0.5 + 0.02",
										"0.11 - 0.02"
									},
									1
								}
							};
						};
						class HeadingLine
						{
							type="line";
							width=4;
							points[]=
							{

								{
									{0.30000001,0.12},
									1
								},

								{
									{0.69999999,0.12},
									1
								}
							};
						};
						class HeadingScale
						{
							type="scale";
							scale=1;
							source="Heading";
							sourceScale=1;
							align="center";
							pos[]=
							{
								"0.21-0.01",
								0
							};
							right[]=
							{
								"0.29-0.01",
								0
							};
							down[]=
							{
								"0.21-0.01",
								0.050000001
							};
							lineXleft=0.059999999;
							lineYright=0.050000001;
							lineXleftMajor=0.059999999;
							lineYrightMajor=0.039999999;
							bottom=0.80000001;
							center=0.5;
							top=0.2;
							step="18/9";
							StepSize="(0.80- 0.2)/20";
							horizontal=1;
							min="none";
							max="none";
							numberEach=5;
							majorLineEach=5;
						};
						class RadarTargets
						{
							type="radar";
							width=4;
							angle=-2.3;
							pos0[]={0.5,0.55500001};
							pos10[]={1.24,1.325};
							points[]=
							{

								{
									{-0.050000001,-0.047297299},
									1
								},

								{
									{0.050000001,-0.047297299},
									1
								},

								{
									{0.050000001,0.047297299},
									1
								},

								{
									{-0.050000001,0.047297299},
									1
								},

								{
									{-0.050000001,-0.047297299},
									1
								}
							};
						};
					};
				};
				class Parallax_HUD
				{
					topLeft="HUD_TOP_L";
					topRight="HUD_TOP_R";
					bottomLeft="HUD_BOT_L";
					borderLeft=0;
					borderRight=0;
					borderTop=0;
					borderBottom=0;
					color[]={0,1,0,1};
					enableParallax=1;
					class Bones
					{
						class PlaneOrientation
						{
							type="fixed";
							pos[]={0.5,0.52999997};
						};
						class WeaponAim
						{
							type="vector";
							source="weapon";
							pos0[]={0.5,0.55500001};
							pos10[]={1.5,1.5549999};
						};
						class Velocity
						{
							type="vector";
							source="velocity";
							pos0[]={0.5,0.52999997};
							pos10[]={1.5,1.53};
						};
						class Level0
						{
							type="horizon";
							pos0[]={0.5,0.52999997};
							pos10[]={1.5,1.53};
							angle=-2.3;
						};
					};
					class Draw
					{
						color[]={0,1,0,1};
						alpha=0.5;
						condition="on";
						class PlaneMovementCrosshair
						{
							type="line";
							width=4;
							points[]=
							{

								{
									"Velocity",
									{0,-0.02},
									1
								},

								{
									"Velocity",
									{0.0099999998,-0.01732},
									1
								},

								{
									"Velocity",
									{0.01732,-0.0099999998},
									1
								},

								{
									"Velocity",
									{0.02,0},
									1
								},

								{
									"Velocity",
									{0.01732,0.0099999998},
									1
								},

								{
									"Velocity",
									{0.0099999998,0.01732},
									1
								},

								{
									"Velocity",
									{0,0.02},
									1
								},

								{
									"Velocity",
									{-0.0099999998,0.01732},
									1
								},

								{
									"Velocity",
									{-0.01732,0.0099999998},
									1
								},

								{
									"Velocity",
									{-0.02,0},
									1
								},

								{
									"Velocity",
									{-0.01732,-0.0099999998},
									1
								},

								{
									"Velocity",
									{-0.0099999998,-0.01732},
									1
								},

								{
									"Velocity",
									{0,-0.02},
									1
								},
								{},

								{
									"Velocity",
									{0.039999999,0},
									1
								},

								{
									"Velocity",
									{0.02,0},
									1
								},
								{},

								{
									"Velocity",
									{-0.039999999,0},
									1
								},

								{
									"Velocity",
									{-0.02,0},
									1
								},
								{},

								{
									"Velocity",
									{0,-0.039999999},
									1
								},

								{
									"Velocity",
									{0,-0.02},
									1
								}
							};
						};
						class MGun
						{
							condition="mgun";
							class Circle
							{
								type="line";
								points[]=
								{

									{
										"WeaponAim",
										{0.0099999998,0},
										1
									},

									{
										"WeaponAim",
										{-0.0099999998,0},
										1
									},
									{},

									{
										"WeaponAim",
										{0,0.0094594602},
										1
									},

									{
										"WeaponAim",
										{0,-0.0094594602},
										1
									},
									{},

									{
										"WeaponAim",
										{0,-0.066216201},
										1
									},

									{
										"WeaponAim",
										{0.048999999,-0.046351399},
										1
									},

									{
										"WeaponAim",
										{0.07,0},
										1
									},

									{
										"WeaponAim",
										{0.048999999,0.046351399},
										1
									},

									{
										"WeaponAim",
										{0,0.066216201},
										1
									},

									{
										"WeaponAim",
										{-0.048999999,0.046351399},
										1
									},

									{
										"WeaponAim",
										{-0.07,0},
										1
									},

									{
										"WeaponAim",
										{-0.048999999,-0.046351399},
										1
									},

									{
										"WeaponAim",
										{0,-0.066216201},
										1
									},
									{},

									{
										"WeaponAim",
										{0,-0.132432},
										1
									},

									{
										"WeaponAim",
										{0.07,-0.115216},
										1
									},

									{
										"WeaponAim",
										{0.1218,-0.066216201},
										1
									},

									{
										"WeaponAim",
										{0.14,0},
										1
									},

									{
										"WeaponAim",
										{0.1218,0.066216201},
										1
									},

									{
										"WeaponAim",
										{0.07,0.115216},
										1
									},

									{
										"WeaponAim",
										{0,0.132432},
										1
									},

									{
										"WeaponAim",
										{-0.07,0.115216},
										1
									},

									{
										"WeaponAim",
										{-0.1218,0.066216201},
										1
									},

									{
										"WeaponAim",
										{-0.14,0},
										1
									},

									{
										"WeaponAim",
										{-0.1218,-0.066216201},
										1
									},

									{
										"WeaponAim",
										{-0.07,-0.115216},
										1
									},

									{
										"WeaponAim",
										{0,-0.132432},
										1
									},
									{},

									{
										"WeaponAim",
										{0,-0.132432},
										1
									},

									{
										"WeaponAim",
										{0,-0.151351},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.07,-0.11469},
										1
									},

									{
										"WeaponAim",
										{-0.079999998,-0.131074},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.121244,-0.066216201},
										1
									},

									{
										"WeaponAim",
										{-0.13856401,-0.075675704},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.14,5.7888099e-009},
										1
									},

									{
										"WeaponAim",
										{-0.16,6.6157799e-009},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.121244,0.066216201},
										1
									},

									{
										"WeaponAim",
										{-0.13856401,0.075675704},
										1
									},
									{},

									{
										"WeaponAim",
										{-0.07,0.11469},
										1
									},

									{
										"WeaponAim",
										{-0.079999998,0.131074},
										1
									},
									{},

									{
										"WeaponAim",
										{1.22392e-008,0.132432},
										1
									},

									{
										"WeaponAim",
										{1.39876e-008,0.151351},
										1
									},
									{},

									{
										"WeaponAim",
										{0.07,0.11469},
										1
									},

									{
										"WeaponAim",
										{0.079999998,0.131074},
										1
									},
									{},

									{
										"WeaponAim",
										{0.121244,0.066216201},
										1
									},

									{
										"WeaponAim",
										{0.13856401,0.075675704},
										1
									},
									{},

									{
										"WeaponAim",
										{0.14,-1.57924e-009},
										1
									},

									{
										"WeaponAim",
										{0.16,-1.80485e-009},
										1
									},
									{},

									{
										"WeaponAim",
										{0.121244,-0.066216201},
										1
									},

									{
										"WeaponAim",
										{0.13856401,-0.075675704},
										1
									},
									{},

									{
										"WeaponAim",
										{0.07,-0.11469},
										1
									},

									{
										"WeaponAim",
										{0.079999998,-0.131074},
										1
									},
									{}
								};
							};
						};
						class BombCrosshairGroup
						{
							type="group";
							condition="bomb";
							class BombCrosshair
							{
								type="line";
								width=4;
								points[]=
								{

									{
										"WeaponAim",
										{0,-0.1},
										1
									},

									{
										"WeaponAim",
										{0.01736,-0.098480001},
										1
									},

									{
										"WeaponAim",
										{0.034200002,-0.093970001},
										1
									},

									{
										"WeaponAim",
										{0.050000001,-0.086599998},
										1
									},

									{
										"WeaponAim",
										{0.064280003,-0.0766},
										1
									},

									{
										"WeaponAim",
										{0.0766,-0.064280003},
										1
									},

									{
										"WeaponAim",
										{0.086599998,-0.050000001},
										1
									},

									{
										"WeaponAim",
										{0.093970001,-0.034200002},
										1
									},

									{
										"WeaponAim",
										{0.098480001,-0.01736},
										1
									},

									{
										"WeaponAim",
										{0.1,0},
										1
									},

									{
										"WeaponAim",
										{0.098480001,0.01736},
										1
									},

									{
										"WeaponAim",
										{0.093970001,0.034200002},
										1
									},

									{
										"WeaponAim",
										{0.086599998,0.050000001},
										1
									},

									{
										"WeaponAim",
										{0.0766,0.064280003},
										1
									},

									{
										"WeaponAim",
										{0.064280003,0.0766},
										1
									},

									{
										"WeaponAim",
										{0.050000001,0.086599998},
										1
									},

									{
										"WeaponAim",
										{0.034200002,0.093970001},
										1
									},

									{
										"WeaponAim",
										{0.01736,0.098480001},
										1
									},

									{
										"WeaponAim",
										{0,0.1},
										1
									},

									{
										"WeaponAim",
										{-0.01736,0.098480001},
										1
									},

									{
										"WeaponAim",
										{-0.034200002,0.093970001},
										1
									},

									{
										"WeaponAim",
										{-0.050000001,0.086599998},
										1
									},

									{
										"WeaponAim",
										{-0.064280003,0.0766},
										1
									},

									{
										"WeaponAim",
										{-0.0766,0.064280003},
										1
									},

									{
										"WeaponAim",
										{-0.086599998,0.050000001},
										1
									},

									{
										"WeaponAim",
										{-0.093970001,0.034200002},
										1
									},

									{
										"WeaponAim",
										{-0.098480001,0.01736},
										1
									},

									{
										"WeaponAim",
										{-0.1,0},
										1
									},

									{
										"WeaponAim",
										{-0.098480001,-0.01736},
										1
									},

									{
										"WeaponAim",
										{-0.093970001,-0.034200002},
										1
									},

									{
										"WeaponAim",
										{-0.086599998,-0.050000001},
										1
									},

									{
										"WeaponAim",
										{-0.0766,-0.064280003},
										1
									},

									{
										"WeaponAim",
										{-0.064280003,-0.0766},
										1
									},

									{
										"WeaponAim",
										{-0.050000001,-0.086599998},
										1
									},

									{
										"WeaponAim",
										{-0.034200002,-0.093970001},
										1
									},

									{
										"WeaponAim",
										{-0.01736,-0.098480001},
										1
									},

									{
										"WeaponAim",
										{0,-0.1},
										1
									},
									{},

									{
										"Velocity",
										0.001,
										"WeaponAim",
										{0,0},
										1
									},

									{
										"Velocity",
										{0,0},
										1
									}
								};
							};
						};
					};
				};
			};
	};
};
