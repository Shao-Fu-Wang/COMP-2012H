@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\Qt6\6.3.2\mingw_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\Qt6\6.3.2\mingw_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\Qt6\6.3.2\mingw_64\plugins
)
%*
EndLocal
