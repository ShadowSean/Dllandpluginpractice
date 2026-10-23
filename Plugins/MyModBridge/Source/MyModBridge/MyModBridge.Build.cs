using System.IO;
using UnrealBuildTool;

public class MyModBridge : ModuleRules
{
    public MyModBridge(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string DllSource = Path.Combine(
                PluginDirectory,
                "ThirdParty",
                "MyNewTestMod",
                "Win64",
                "MyNewTestMod.dll"
            );

            if (File.Exists(DllSource))
            {
                RuntimeDependencies.Add(
                    "$(TargetOutputDir)/MyNewTestMod.dll",
                    DllSource
                );
            }
            else
            {
                System.Console.WriteLine(
                    "WARNING: MyNewTestMod.dll not found at "
                    + DllSource
                );
            }
        }
    }
}