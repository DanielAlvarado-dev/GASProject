// Copyright Daniel Alvarado

using UnrealBuildTool;
using System.Collections.Generic;

public class GASProjectTarget : TargetRules
{
	public GASProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GASProject" } );
	}
}
