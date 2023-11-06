# ESP
For ESP32 Projects

<h2>Hello World</h2>
If facing problems:
identifier "CONFIG_IDF_TARGET" is undefined
identifier "CONFIG_FREERTOS_HZ" is undefined <br>
Then do some changes based on this https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/C_CPP_CONFIGURATION.md
In short Add this line to the <I>c_cpp_properties.json</I>
<b>"compileCommands": "${workspaceFolder}/build/compile_commands.json"</b>,
or 
change this line in <i>settings.json</i> from "default" to "Tag Parser"
<b>"C_Cpp.intelliSenseEngine": "Tag Parser"</b>

