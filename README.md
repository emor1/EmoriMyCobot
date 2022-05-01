# MyCobot


# フォルダー
## mycobot_arduino_test
mycobotの動作確認用として、PlatformIOで作成。mycobotの簡単な動作確認が行える。

## JissenRobotControl
このディレクトリでは実践ロボット制御を参考にロボットアームの制御を実装していく

## libs
このディレクトリにMyCobotのライブラリであるMyCobotBasicが格納されている。

# platform.iniのライブラリ設定
libsフォルダにMyCobotのライブラリを配置しているため、iniファイルではこのようにlibsの下にある「MyCobotBasic」フォルダを指定するようする。またパスはその都度調整する。


mycobot_arduino_testの例
```
lib_deps = 
    m5stack/M5Stack@^0.4.0
    ../libs/MyCobotBasic
```
