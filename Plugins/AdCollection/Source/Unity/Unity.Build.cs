// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class Unity : ModuleRules
{
	public Unity(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Unity/Public"
				
				// ... add public include paths required here ...
			}
			);

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "AdCollection",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
        

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PrivateIncludePaths.Add("Private/IOS");
            PublicAdditionalFrameworks.Add(
                new UEBuildFramework(
                "UnityAds",														// Framework name
                "../ThirdParty/ThirdPartyFrameworks/UnityAds.embeddedframework.zip")
            );

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "AdsUtil",														// Framework name
            "../ThirdParty/ThirdPartyFrameworks/AdsUtil.embeddedframework.zip")
            );


            PublicFrameworks.AddRange(
            new string[]
            {
                "EventKit",
                "MediaPlayer",
                "AdSupport",
                "CoreLocation",
                "SystemConfiguration",
                "MessageUI",
                "Security",
                "CoreTelephony"
            }
            );

        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateIncludePaths.Add("Private/Android");
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                "Launch",
                }
                );

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "Unity_UPL.xml")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            PrivateIncludePaths.Add("Private/Windows");
        }
        else if(Target.Platform == UnrealTargetPlatform.Mac)
        {
            PrivateIncludePaths.Add("Private/Mac");
        }
        else
        {
            PrecompileForTargets = PrecompileTargetsType.None;
        }
    }
}
