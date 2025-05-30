// Copyright Daniel Alvarado

using UnrealBuildTool;

public class GASProject : ModuleRules
{
	public GASProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" , "GameplayAbilities", "UMG", "MotionWarping"});

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" ,"Niagara", "AIModule", "NavigationSystem" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
