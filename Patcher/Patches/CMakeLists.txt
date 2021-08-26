target_sources(Patcher PRIVATE 
	"IPatch.cpp"
	"PatchManager.cpp"
)

add_subdirectory(CBasePositionableObject)
add_subdirectory(CBloonsTD5Game)
add_subdirectory(CMainMenuScreen_Tablet)
add_subdirectory(CTextObject)
add_subdirectory(Global)
add_subdirectory(Win32)
add_subdirectory(WinRenderLayer)