// Copyright Daniel Alvarado

using UnrealBuildTool;
using System.Collections.Generic;

public class GASProjectEditorTarget : TargetRules
{
	public GASProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GASProject" } );
	}
}
