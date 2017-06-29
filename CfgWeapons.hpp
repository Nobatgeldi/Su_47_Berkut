class CfgWeapons
{

	class CannonCore;
	class Su_R73M1Launcher;
	class H_PilotHelmetFighter_O;
	class gatling_30mm;
	class FakeWeapon;

	class Su47_R73M1Launcher: Su_R73M1Launcher
	{
		displayName="R-73M1 Archer";
		displayNameMagazine="R-73M1 Archer";
		shortNameMagazine="R-73M1 Archer";
		magazines[]=
		{
			"Su47_R73M1"
		};
	};
	class Su47_R60Launcher: Su_R73M1Launcher
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
