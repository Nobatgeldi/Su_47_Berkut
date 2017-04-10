class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		su47_pilot="pilot_plane_cas_01";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class su47_pilot: Crew
		{
			file="\Mikoyan-Mig-29\anim\mig_pilot.rtm";
			interpolateTo[]=
			{
				"su47_pilot_dead",
				1
			};
		};
		class su47_pilot_dead: DefaultDie
		{
			actions="DeadActions";
			speed=0.5;
			looped="false";
			terminal=1;
			file="\Mikoyan-Mig-29\anim\mig_pilot_dead.rtm";
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
	};
};
