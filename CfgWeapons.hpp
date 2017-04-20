class CfgWeapons
{

	class CannonCore;
	class MissileLauncher;
	class H_PilotHelmetFighter_O;
	class gatling_30mm;
	class FakeWeapon;

	class Su47_R73Launcher: MissileLauncher
	{
		canLock=2;
		autoFire=0;
		displayName="R-73 Archer";
		displayNameMagazine="R-73 Archer";
		shortNameMagazine="R-73 Archer";
		magazines[]=
		{
			"Su47_R73"
		};
		cursorAim="EmptyCursor";
		cursor="EmptyCursor";
		minRange=300;
		minRangeProbab=0.025;
		maxRange=9000;
		maxRangeProbab=0.0099999998;
		sound[]={"A3\Sounds_F\weapons\Rockets\rocket_fly_2",db+47,1};
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\weapons\Rockets\missile_2",
				1.12202,
				1.3,
				1000
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			weaponSoundEffect="DefaultRifle";
		};
		soundFly[]=
		{
			"A3\Sounds_F\weapons\Rockets\rocket_fly_2",
			1,
			1.5,
			700
		};
		lockingTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			0.316228,
			1
		};
		lockedTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.316228,
			2.5
		};
		reloadTime=0.1;
		magazineReloadTime=0.1;
		holdsterAnimValue=3;
		weaponLockSystem="2 + 16 + 4";
		weaponLockDelay=3;
		textureType="semi";
	};
	class Su47_R73M1Launcher: Su47_R73Launcher
	{
		displayName="R-73M1 Archer";
		displayNameMagazine="R-73M1 Archer";
		shortNameMagazine="R-73M1 Archer";
		magazines[]=
		{
			"Su47_R73M1"
		};
	};
	class Su47_R60Launcher: Su47_R73Launcher
	{
		displayName="R-60 Archer";
		displayNameMagazine="R-60 Archer";
		shortNameMagazine="R-60 Archer";
		magazines[]=
		{
			"Su47_R60"
		};
	};
	class Su47_fake_weapon: FakeWeapon
	{
		displayName="Safe mod";
		displayNameMagazine="Safe mod";
		shortNameMagazine="Safe mod";
		magazines[]=
		{
		};
	};
};
