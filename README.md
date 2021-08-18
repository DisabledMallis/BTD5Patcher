# BTD5 Patcher
Since I haven't really worked on NKHook5, I figured I wouldn't let the code I wrote for it become entirely useless. Most of the concepts and goals for NKHook5 were out of reach for me to do alone, and the result I wanted to make was quite complecated for a modding community who is used to modifying assets and leaving the game's code untouched. While this community was limited, there was never a clear and simple way for these modders to expand the functionality of the game in a simple way, which looking back is really what they needed all along.

This mod is here to achieve what I should have been trying to achieve this whole time.

# Bug & Feature reports
To report a bug or request a feature, send me a message on the NKHook5 discord. I'll take a look there. Make sure to **ping** me, not DM! (Bug reports and feature requests should all be public!)

# Building
If you want to build the project yourself, make sure to follow these build instructions! Make sure to have `MSVC` installed, along with `CMake`.

## Dependencies
BTD5 Patcher uses PolyHook2 as a hooking library. You'll need to have that submodule updated.
```git submodule update --init --recursive```
This command will update all of the required submodules.

### Building PolyHook2
Now that PLH is updated, we need to build it. This can be done with the following commands:
```
cd Patcher/Lib/PolyHook_2_0
cmake -A Win32 .
cmake -B"./_build" -DCMAKE_INSTALL_PREFIX="./_install/" -DPOLYHOOK_BUILD_SHARED_LIB=ON
cmake --build "./_build" --config Release --target INSTALL
```

### Building Patcher & Loader
Now we have PLH built, Patcher can now be built. We want to build both Patcher & Loader. The Loader is a dll that will be used to inject Patcher when BTD5-Win.exe is opened. To build these, traverse back to the root directory of the repository, then run these commands.
```
cmake -A Win32 .
cmake --build . --config Release
```


### Conclusion
Congrats! BTD5 Patcher has been built! You can find the built binaries in the `Binaries` folder.