@ECHO off
SET "dir=%homedrive%%homepath%\Documents\BanishedMod\translation_th"
@ECHO on
COPY "Release\BanishedTHUnicodeFix.exe" "%dir%\UnicodeFix32.exe"
COPY "x64\Release\BanishedTHUnicodeFix.exe" "%dir%\UnicodeFix64.exe"

@ECHO off
:: delay hack for win xp
ping 127.0.0.1 -n 2 > NUL