windows下设置qbs
1."qbs setup-toolchains --detect"自动构建toolchains
2."qbs setup-qt path_of_qmake custom_profile_name"，生成自定义profile，自动关联到之前生成的toolchains.
	如：qbs setup-qt C:\Qt\Qt5.11.2\5.11.2\msvc2017_64\bin\qmake.exe my
3.生成vs工程
	qbs generate -g visualstudio2017 -d ../build_xxxx profile:my
注意：
	一定要先setup-toolchains,再setup-qt。否则生成的profile不能关联到toolchains;
	指定使用确定的profile要放在命令行的最后。
	