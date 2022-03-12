# QtWiznetCanBus

## Open Project in Qt
- [File] -> [Open File or Project..]
  - Choose `CMakeLists.txt` & [Open]
  - Import MinGW Kit: Desktop Qt 5.15.2 MinGW 64bit

## Build
> Crtl + B or Right Click -> [Build]

## Copy dll file to Qt plugin directory
```
cp libQtWiznetCanBusPlugin.dll {YOUR_QT_INSTALL_DIR}/5.15.2/mingw81_64/plugins/canbus
```

## Test plugins using Qt default example
- [Welcome] -> [Examples] -> CAN Bus example
- Enjoy :)
