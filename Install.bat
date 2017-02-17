@ECHO off
SET "bin=\Release\BanishedTHUnicodeFix.exe"
SET "dir=..\BanishedTranslationTH\"
@ECHO on
COPY "Win32%bin%" "%dir%UnicodeFix32.exe"
COPY "x64%bin%" "%dir%UnicodeFix64.exe"
