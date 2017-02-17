@ECHO off
SET "dir=..\BanishedTranslationTH"
@ECHO on
COPY "Release\BanishedTHUnicodeFix.exe" "%dir%\UnicodeFix32.exe"
COPY "x64\Release\BanishedTHUnicodeFix.exe" "%dir%\UnicodeFix64.exe"
