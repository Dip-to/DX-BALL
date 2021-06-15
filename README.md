# Header_ver
* Library Pre-requisites : 
  * ```Linux```:
    * Debian Based Distributions : 
       ```build-essential``` ```libsdl2-2.0```  ```libsdl2-dev``` ```libsdl2-image-dev``` ```libsdl2-ttf-dev``` ```libsdl2-mixer-dev```
    * Others : Install equaivalent packages of the above mentioned. 
    * Alternatively you can run ```setup.sh```
  * Compile with ```make``` 
* Known Bugs:
    * Window resizing doesn't work on Windows due to Microsoft's ```OpenGL``` implementaion issue mentioned [here](https://github.com/libsdl-org/SDL/issues/1059)
    * If the user delays at the youtube link dialogue box the program stops responding as both win32 and posix thread models consider holding the main thread for long as unresponsive. We probably need to work with multithreading to resolve this issue.
