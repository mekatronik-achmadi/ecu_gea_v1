<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.4">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="stm32">
<description>ST Cortex-M3 STM32F101/103 processor family  in LQFP100, 64, 48, BGA100, 64 and QFN36 pin versions</description>
<packages>
<package name="TQFP64">
<wire x1="-4.8" y1="4.4" x2="-4.4" y2="4.8" width="0.2032" layer="21"/>
<wire x1="-4.4" y1="4.8" x2="4.4" y2="4.8" width="0.2032" layer="21"/>
<wire x1="4.4" y1="4.8" x2="4.8" y2="4.4" width="0.2032" layer="21"/>
<wire x1="4.8" y1="4.4" x2="4.8" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="4.8" y1="-4.4" x2="4.4" y2="-4.8" width="0.2032" layer="21"/>
<wire x1="4.4" y1="-4.8" x2="-4.4" y2="-4.8" width="0.2032" layer="21"/>
<wire x1="-4.4" y1="-4.8" x2="-4.8" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="-4.8" y1="-4.4" x2="-4.8" y2="4.4" width="0.2032" layer="21"/>
<circle x="-4" y="4" radius="0.2827" width="0.254" layer="21"/>
<smd name="1" x="-5.7" y="3.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="2" x="-5.7" y="3.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="3" x="-5.7" y="2.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="4" x="-5.7" y="2.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="5" x="-5.7" y="1.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="6" x="-5.7" y="1.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="7" x="-5.7" y="0.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="8" x="-5.7" y="0.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="9" x="-5.7" y="-0.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="10" x="-5.7" y="-0.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="11" x="-5.7" y="-1.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="12" x="-5.7" y="-1.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="13" x="-5.7" y="-2.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="14" x="-5.7" y="-2.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="15" x="-5.7" y="-3.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="16" x="-5.7" y="-3.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="17" x="-3.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="18" x="-3.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="19" x="-2.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="20" x="-2.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="21" x="-1.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="22" x="-1.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="23" x="-0.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="24" x="-0.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="25" x="0.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="26" x="0.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="27" x="1.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="28" x="1.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="29" x="2.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="30" x="2.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="31" x="3.25" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="32" x="3.75" y="-5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="33" x="5.7" y="-3.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="34" x="5.7" y="-3.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="35" x="5.7" y="-2.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="36" x="5.7" y="-2.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="37" x="5.7" y="-1.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="38" x="5.7" y="-1.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="39" x="5.7" y="-0.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="40" x="5.7" y="-0.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="41" x="5.7" y="0.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="42" x="5.7" y="0.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="43" x="5.7" y="1.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="44" x="5.7" y="1.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="45" x="5.7" y="2.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="46" x="5.7" y="2.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="47" x="5.7" y="3.25" dx="1.2" dy="0.3" layer="1"/>
<smd name="48" x="5.7" y="3.75" dx="1.2" dy="0.3" layer="1"/>
<smd name="49" x="3.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="50" x="3.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="51" x="2.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="52" x="2.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="53" x="1.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="54" x="1.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="55" x="0.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="56" x="0.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="57" x="-0.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="58" x="-0.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="59" x="-1.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="60" x="-1.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="61" x="-2.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="62" x="-2.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="63" x="-3.25" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<smd name="64" x="-3.75" y="5.7" dx="0.3" dy="1.2" layer="1"/>
<text x="-3.81" y="6.604" size="1.778" layer="25">&gt;NAME</text>
<text x="-4.064" y="-1.7701" size="1.778" layer="27">&gt;VALUE</text>
<rectangle x1="-6" y1="3.65" x2="-4.8" y2="3.85" layer="21"/>
<rectangle x1="-6" y1="3.15" x2="-4.8" y2="3.35" layer="21"/>
<rectangle x1="-6" y1="2.65" x2="-4.8" y2="2.85" layer="21"/>
<rectangle x1="-6" y1="2.15" x2="-4.8" y2="2.35" layer="21"/>
<rectangle x1="-6" y1="1.65" x2="-4.8" y2="1.85" layer="21"/>
<rectangle x1="-6" y1="1.15" x2="-4.8" y2="1.35" layer="21"/>
<rectangle x1="-6" y1="0.65" x2="-4.8" y2="0.85" layer="21"/>
<rectangle x1="-6" y1="0.15" x2="-4.8" y2="0.35" layer="21"/>
<rectangle x1="-6" y1="-0.35" x2="-4.8" y2="-0.15" layer="21"/>
<rectangle x1="-6" y1="-0.85" x2="-4.8" y2="-0.65" layer="21"/>
<rectangle x1="-6" y1="-1.35" x2="-4.8" y2="-1.15" layer="21"/>
<rectangle x1="-6" y1="-1.85" x2="-4.8" y2="-1.65" layer="21"/>
<rectangle x1="-6" y1="-2.35" x2="-4.8" y2="-2.15" layer="21"/>
<rectangle x1="-6" y1="-2.85" x2="-4.8" y2="-2.65" layer="21"/>
<rectangle x1="-6" y1="-3.35" x2="-4.8" y2="-3.15" layer="21"/>
<rectangle x1="-6" y1="-3.85" x2="-4.8" y2="-3.65" layer="21"/>
<rectangle x1="-3.85" y1="-6" x2="-3.65" y2="-4.8" layer="21"/>
<rectangle x1="-3.35" y1="-6" x2="-3.15" y2="-4.8" layer="21"/>
<rectangle x1="-2.85" y1="-6" x2="-2.65" y2="-4.8" layer="21"/>
<rectangle x1="-2.35" y1="-6" x2="-2.15" y2="-4.8" layer="21"/>
<rectangle x1="-1.85" y1="-6" x2="-1.65" y2="-4.8" layer="21"/>
<rectangle x1="-1.35" y1="-6" x2="-1.15" y2="-4.8" layer="21"/>
<rectangle x1="-0.85" y1="-6" x2="-0.65" y2="-4.8" layer="21"/>
<rectangle x1="-0.35" y1="-6" x2="-0.15" y2="-4.8" layer="21"/>
<rectangle x1="0.15" y1="-6" x2="0.35" y2="-4.8" layer="21"/>
<rectangle x1="0.65" y1="-6" x2="0.85" y2="-4.8" layer="21"/>
<rectangle x1="1.15" y1="-6" x2="1.35" y2="-4.8" layer="21"/>
<rectangle x1="1.65" y1="-6" x2="1.85" y2="-4.8" layer="21"/>
<rectangle x1="2.15" y1="-6" x2="2.35" y2="-4.8" layer="21"/>
<rectangle x1="2.65" y1="-6" x2="2.85" y2="-4.8" layer="21"/>
<rectangle x1="3.15" y1="-6" x2="3.35" y2="-4.8" layer="21"/>
<rectangle x1="3.65" y1="-6" x2="3.85" y2="-4.8" layer="21"/>
<rectangle x1="4.8" y1="-3.85" x2="6" y2="-3.65" layer="21"/>
<rectangle x1="4.8" y1="-3.35" x2="6" y2="-3.15" layer="21"/>
<rectangle x1="4.8" y1="-2.85" x2="6" y2="-2.65" layer="21"/>
<rectangle x1="4.8" y1="-2.35" x2="6" y2="-2.15" layer="21"/>
<rectangle x1="4.8" y1="-1.85" x2="6" y2="-1.65" layer="21"/>
<rectangle x1="4.8" y1="-1.35" x2="6" y2="-1.15" layer="21"/>
<rectangle x1="4.8" y1="-0.85" x2="6" y2="-0.65" layer="21"/>
<rectangle x1="4.8" y1="-0.35" x2="6" y2="-0.15" layer="21"/>
<rectangle x1="4.8" y1="0.15" x2="6" y2="0.35" layer="21"/>
<rectangle x1="4.8" y1="0.65" x2="6" y2="0.85" layer="21"/>
<rectangle x1="4.8" y1="1.15" x2="6" y2="1.35" layer="21"/>
<rectangle x1="4.8" y1="1.65" x2="6" y2="1.85" layer="21"/>
<rectangle x1="4.8" y1="2.15" x2="6" y2="2.35" layer="21"/>
<rectangle x1="4.8" y1="2.65" x2="6" y2="2.85" layer="21"/>
<rectangle x1="4.8" y1="3.15" x2="6" y2="3.35" layer="21"/>
<rectangle x1="4.8" y1="3.65" x2="6" y2="3.85" layer="21"/>
<rectangle x1="3.65" y1="4.8" x2="3.85" y2="6" layer="21"/>
<rectangle x1="3.15" y1="4.8" x2="3.35" y2="6" layer="21"/>
<rectangle x1="2.65" y1="4.8" x2="2.85" y2="6" layer="21"/>
<rectangle x1="2.15" y1="4.8" x2="2.35" y2="6" layer="21"/>
<rectangle x1="1.65" y1="4.8" x2="1.85" y2="6" layer="21"/>
<rectangle x1="1.15" y1="4.8" x2="1.35" y2="6" layer="21"/>
<rectangle x1="0.65" y1="4.8" x2="0.85" y2="6" layer="21"/>
<rectangle x1="0.15" y1="4.8" x2="0.35" y2="6" layer="21"/>
<rectangle x1="-0.35" y1="4.8" x2="-0.15" y2="6" layer="21"/>
<rectangle x1="-0.85" y1="4.8" x2="-0.65" y2="6" layer="21"/>
<rectangle x1="-1.35" y1="4.8" x2="-1.15" y2="6" layer="21"/>
<rectangle x1="-1.85" y1="4.8" x2="-1.65" y2="6" layer="21"/>
<rectangle x1="-2.35" y1="4.8" x2="-2.15" y2="6" layer="21"/>
<rectangle x1="-2.85" y1="4.8" x2="-2.65" y2="6" layer="21"/>
<rectangle x1="-3.35" y1="4.8" x2="-3.15" y2="6" layer="21"/>
<rectangle x1="-3.85" y1="4.8" x2="-3.65" y2="6" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PORT_A_L">
<wire x1="7.62" y1="10.16" x2="-2.54" y2="10.16" width="0.254" layer="94"/>
<wire x1="-2.54" y1="10.16" x2="-2.54" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-12.7" x2="7.62" y2="-12.7" width="0.254" layer="94"/>
<text x="-2.54" y="10.16" size="1.27" layer="95">&gt;NAME</text>
<pin name="PA0" x="-7.62" y="7.62" length="middle"/>
<pin name="PA1" x="-7.62" y="5.08" length="middle"/>
<pin name="PA2" x="-7.62" y="2.54" length="middle"/>
<pin name="PA3" x="-7.62" y="0" length="middle"/>
<pin name="PA4" x="-7.62" y="-2.54" length="middle"/>
<pin name="PA5" x="-7.62" y="-5.08" length="middle"/>
<pin name="PA6" x="-7.62" y="-7.62" length="middle"/>
<pin name="PA7" x="-7.62" y="-10.16" length="middle"/>
</symbol>
<symbol name="PORT_A_H">
<wire x1="7.62" y1="12.7" x2="-2.54" y2="12.7" width="0.254" layer="94"/>
<wire x1="-2.54" y1="12.7" x2="-2.54" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-10.16" x2="7.62" y2="-10.16" width="0.254" layer="94"/>
<text x="-2.54" y="12.7" size="1.27" layer="95">&gt;NAME</text>
<pin name="PA8" x="-7.62" y="10.16" length="middle"/>
<pin name="PA9" x="-7.62" y="7.62" length="middle"/>
<pin name="PA10" x="-7.62" y="5.08" length="middle"/>
<pin name="PA11" x="-7.62" y="2.54" length="middle"/>
<pin name="PA12" x="-7.62" y="0" length="middle"/>
<pin name="PA13" x="-7.62" y="-2.54" length="middle"/>
<pin name="PA14" x="-7.62" y="-5.08" length="middle"/>
<pin name="PA15" x="-7.62" y="-7.62" length="middle"/>
</symbol>
<symbol name="PORT_B_L">
<wire x1="-5.08" y1="12.7" x2="5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="-5.08" y2="-10.16" width="0.254" layer="94"/>
<text x="-5.08" y="12.7" size="1.27" layer="95">&gt;NAME</text>
<pin name="PB0" x="10.16" y="10.16" length="middle" rot="R180"/>
<pin name="PB1" x="10.16" y="7.62" length="middle" rot="R180"/>
<pin name="PB2" x="10.16" y="5.08" length="middle" rot="R180"/>
<pin name="PB3" x="10.16" y="2.54" length="middle" rot="R180"/>
<pin name="PB4" x="10.16" y="0" length="middle" rot="R180"/>
<pin name="PB5" x="10.16" y="-2.54" length="middle" rot="R180"/>
<pin name="PB6" x="10.16" y="-5.08" length="middle" rot="R180"/>
<pin name="PB7" x="10.16" y="-7.62" length="middle" rot="R180"/>
</symbol>
<symbol name="PORT_B_H">
<wire x1="-5.08" y1="10.16" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="-12.7" x2="-5.08" y2="-12.7" width="0.254" layer="94"/>
<text x="-5.08" y="10.16" size="1.27" layer="95">&gt;NAME</text>
<pin name="PB8" x="10.16" y="7.62" length="middle" rot="R180"/>
<pin name="PB9" x="10.16" y="5.08" length="middle" rot="R180"/>
<pin name="PB10" x="10.16" y="2.54" length="middle" rot="R180"/>
<pin name="PB11" x="10.16" y="0" length="middle" rot="R180"/>
<pin name="PB12" x="10.16" y="-2.54" length="middle" rot="R180"/>
<pin name="PB13" x="10.16" y="-5.08" length="middle" rot="R180"/>
<pin name="PB14" x="10.16" y="-7.62" length="middle" rot="R180"/>
<pin name="PB15" x="10.16" y="-10.16" length="middle" rot="R180"/>
</symbol>
<symbol name="PORT_C_L">
<wire x1="5.08" y1="12.7" x2="-5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="-5.08" y1="12.7" x2="-5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-10.16" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<text x="-5.08" y="12.7" size="1.27" layer="95">&gt;NAME</text>
<pin name="PC0" x="-10.16" y="10.16" length="middle"/>
<pin name="PC1" x="-10.16" y="7.62" length="middle"/>
<pin name="PC2" x="-10.16" y="5.08" length="middle"/>
<pin name="PC3" x="-10.16" y="2.54" length="middle"/>
<pin name="PC4" x="-10.16" y="0" length="middle"/>
<pin name="PC5" x="-10.16" y="-2.54" length="middle"/>
<pin name="PC6" x="-10.16" y="-5.08" length="middle"/>
<pin name="PC7" x="-10.16" y="-7.62" length="middle"/>
</symbol>
<symbol name="PORT_C_H">
<wire x1="5.08" y1="10.16" x2="-5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="10.16" x2="-5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-12.7" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<text x="-5.08" y="10.16" size="1.27" layer="95">&gt;NAME</text>
<pin name="PC13" x="-10.16" y="-5.08" length="middle"/>
<pin name="PC14" x="-10.16" y="-7.62" length="middle"/>
<pin name="PC15" x="-10.16" y="-10.16" length="middle"/>
<pin name="PC8" x="-10.16" y="7.62" length="middle"/>
<pin name="PC9" x="-10.16" y="5.08" length="middle"/>
<pin name="PC10" x="-10.16" y="2.54" length="middle"/>
<pin name="PC11" x="-10.16" y="0" length="middle"/>
<pin name="PC12" x="-10.16" y="-2.54" length="middle"/>
</symbol>
<symbol name="VCC_VDD_M">
<wire x1="5.08" y1="22.86" x2="-5.08" y2="22.86" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-22.86" x2="5.08" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-5.08" y1="22.86" x2="-5.08" y2="-22.86" width="0.254" layer="94"/>
<text x="-5.08" y="22.86" size="1.27" layer="95">&gt;NAME</text>
<pin name="VDD_1" x="-10.16" y="20.32" length="middle" direction="pwr"/>
<pin name="VDD_2" x="-10.16" y="15.24" length="middle" direction="pwr"/>
<pin name="VDD_3" x="-10.16" y="10.16" length="middle" direction="pwr"/>
<pin name="VSS_1" x="-10.16" y="-5.08" length="middle" direction="pwr"/>
<pin name="VSS_2" x="-10.16" y="-10.16" length="middle" direction="pwr"/>
<pin name="VSS_3" x="-10.16" y="-15.24" length="middle" direction="pwr"/>
<pin name="VDD_4" x="-10.16" y="5.08" length="middle" direction="pwr"/>
<pin name="VSS_4" x="-10.16" y="-20.32" length="middle" direction="pwr"/>
</symbol>
<symbol name="PORT_D_3">
<wire x1="-5.08" y1="5.08" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="-5.08" x2="-5.08" y2="-5.08" width="0.254" layer="94"/>
<text x="-5.08" y="5.08" size="1.27" layer="95">&gt;NAME</text>
<pin name="PD0/OSC&lt;=" x="10.16" y="2.54" length="middle" rot="R180"/>
<pin name="PD1/OSC=&gt;" x="10.16" y="0" length="middle" rot="R180"/>
<pin name="PD2" x="10.16" y="-2.54" length="middle" rot="R180"/>
</symbol>
<symbol name="BAT_AN_M">
<wire x1="-5.08" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="-7.62" x2="-5.08" y2="-7.62" width="0.254" layer="94"/>
<text x="-5.08" y="7.62" size="1.27" layer="95">&gt;NAME</text>
<pin name="VBAT" x="10.16" y="5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="VSSA" x="10.16" y="-5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="VDDA" x="10.16" y="0" length="middle" direction="pwr" rot="R180"/>
</symbol>
<symbol name="BOOT_RST">
<wire x1="-5.08" y1="5.08" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="-5.08" x2="-5.08" y2="-5.08" width="0.254" layer="94"/>
<text x="-5.08" y="-7.62" size="1.27" layer="95">&gt;VALUE</text>
<text x="-5.08" y="5.08" size="1.27" layer="95">&gt;NAME</text>
<pin name="NRST" x="10.16" y="2.54" length="middle" direction="in" function="dot" rot="R180"/>
<pin name="BOOT0" x="10.16" y="-2.54" length="middle" direction="in" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="STM32F10XRXT6" prefix="U">
<description>STM32F101/103 64pin LQFP</description>
<gates>
<gate name="PORTA_L" symbol="PORT_A_L" x="-15.24" y="45.72"/>
<gate name="PORTA_H" symbol="PORT_A_H" x="-15.24" y="17.78"/>
<gate name="PORTB_L" symbol="PORT_B_L" x="7.62" y="43.18"/>
<gate name="PORTB_H" symbol="PORT_B_H" x="7.62" y="20.32"/>
<gate name="PORTC_L" symbol="PORT_C_L" x="-12.7" y="-7.62"/>
<gate name="PORTC_H" symbol="PORT_C_H" x="-12.7" y="-30.48"/>
<gate name="POWER" symbol="VCC_VDD_M" x="-12.7" y="-68.58"/>
<gate name="PORTD/OSC" symbol="PORT_D_3" x="7.62" y="0"/>
<gate name="AN_POWER" symbol="BAT_AN_M" x="7.62" y="-15.24"/>
<gate name="RESET" symbol="BOOT_RST" x="7.62" y="-30.48"/>
</gates>
<devices>
<device name="" package="TQFP64">
<connects>
<connect gate="AN_POWER" pin="VBAT" pad="1"/>
<connect gate="AN_POWER" pin="VDDA" pad="13"/>
<connect gate="AN_POWER" pin="VSSA" pad="12"/>
<connect gate="PORTA_H" pin="PA10" pad="43"/>
<connect gate="PORTA_H" pin="PA11" pad="44"/>
<connect gate="PORTA_H" pin="PA12" pad="45"/>
<connect gate="PORTA_H" pin="PA13" pad="46"/>
<connect gate="PORTA_H" pin="PA14" pad="49"/>
<connect gate="PORTA_H" pin="PA15" pad="50"/>
<connect gate="PORTA_H" pin="PA8" pad="41"/>
<connect gate="PORTA_H" pin="PA9" pad="42"/>
<connect gate="PORTA_L" pin="PA0" pad="14"/>
<connect gate="PORTA_L" pin="PA1" pad="15"/>
<connect gate="PORTA_L" pin="PA2" pad="16"/>
<connect gate="PORTA_L" pin="PA3" pad="17"/>
<connect gate="PORTA_L" pin="PA4" pad="20"/>
<connect gate="PORTA_L" pin="PA5" pad="21"/>
<connect gate="PORTA_L" pin="PA6" pad="22"/>
<connect gate="PORTA_L" pin="PA7" pad="23"/>
<connect gate="PORTB_H" pin="PB10" pad="29"/>
<connect gate="PORTB_H" pin="PB11" pad="30"/>
<connect gate="PORTB_H" pin="PB12" pad="33"/>
<connect gate="PORTB_H" pin="PB13" pad="34"/>
<connect gate="PORTB_H" pin="PB14" pad="35"/>
<connect gate="PORTB_H" pin="PB15" pad="36"/>
<connect gate="PORTB_H" pin="PB8" pad="61"/>
<connect gate="PORTB_H" pin="PB9" pad="62"/>
<connect gate="PORTB_L" pin="PB0" pad="26"/>
<connect gate="PORTB_L" pin="PB1" pad="27"/>
<connect gate="PORTB_L" pin="PB2" pad="28"/>
<connect gate="PORTB_L" pin="PB3" pad="55"/>
<connect gate="PORTB_L" pin="PB4" pad="56"/>
<connect gate="PORTB_L" pin="PB5" pad="57"/>
<connect gate="PORTB_L" pin="PB6" pad="58"/>
<connect gate="PORTB_L" pin="PB7" pad="59"/>
<connect gate="PORTC_H" pin="PC10" pad="51"/>
<connect gate="PORTC_H" pin="PC11" pad="52"/>
<connect gate="PORTC_H" pin="PC12" pad="53"/>
<connect gate="PORTC_H" pin="PC13" pad="2"/>
<connect gate="PORTC_H" pin="PC14" pad="3"/>
<connect gate="PORTC_H" pin="PC15" pad="4"/>
<connect gate="PORTC_H" pin="PC8" pad="39"/>
<connect gate="PORTC_H" pin="PC9" pad="40"/>
<connect gate="PORTC_L" pin="PC0" pad="8"/>
<connect gate="PORTC_L" pin="PC1" pad="9"/>
<connect gate="PORTC_L" pin="PC2" pad="10"/>
<connect gate="PORTC_L" pin="PC3" pad="11"/>
<connect gate="PORTC_L" pin="PC4" pad="24"/>
<connect gate="PORTC_L" pin="PC5" pad="25"/>
<connect gate="PORTC_L" pin="PC6" pad="37"/>
<connect gate="PORTC_L" pin="PC7" pad="38"/>
<connect gate="PORTD/OSC" pin="PD0/OSC&lt;=" pad="5"/>
<connect gate="PORTD/OSC" pin="PD1/OSC=&gt;" pad="6"/>
<connect gate="PORTD/OSC" pin="PD2" pad="54"/>
<connect gate="POWER" pin="VDD_1" pad="32"/>
<connect gate="POWER" pin="VDD_2" pad="48"/>
<connect gate="POWER" pin="VDD_3" pad="64"/>
<connect gate="POWER" pin="VDD_4" pad="19"/>
<connect gate="POWER" pin="VSS_1" pad="31"/>
<connect gate="POWER" pin="VSS_2" pad="47"/>
<connect gate="POWER" pin="VSS_3" pad="63"/>
<connect gate="POWER" pin="VSS_4" pad="18"/>
<connect gate="RESET" pin="BOOT0" pad="60"/>
<connect gate="RESET" pin="NRST" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X16">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="15.24" y1="0.635" x2="15.875" y2="1.27" width="0.1524" layer="21"/>
<wire x1="15.875" y1="1.27" x2="17.145" y2="1.27" width="0.1524" layer="21"/>
<wire x1="17.145" y1="1.27" x2="17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="17.78" y1="0.635" x2="17.78" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="17.78" y1="-0.635" x2="17.145" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="17.145" y1="-1.27" x2="15.875" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="15.875" y1="-1.27" x2="15.24" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.795" y1="1.27" x2="12.065" y2="1.27" width="0.1524" layer="21"/>
<wire x1="12.065" y1="1.27" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="12.7" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-0.635" x2="12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="13.335" y2="1.27" width="0.1524" layer="21"/>
<wire x1="13.335" y1="1.27" x2="14.605" y2="1.27" width="0.1524" layer="21"/>
<wire x1="14.605" y1="1.27" x2="15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="15.24" y1="0.635" x2="15.24" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="15.24" y1="-0.635" x2="14.605" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="14.605" y1="-1.27" x2="13.335" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="13.335" y1="-1.27" x2="12.7" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-1.27" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.795" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="10.795" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="12.065" y1="-1.27" x2="10.795" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="1.27" x2="-10.795" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="1.27" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-0.635" x2="-10.795" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="1.27" x2="-8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-1.27" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="0.635" x2="-14.605" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="1.27" x2="-13.335" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-13.335" y1="1.27" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-12.7" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-0.635" x2="-13.335" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-13.335" y1="-1.27" x2="-14.605" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="-1.27" x2="-15.24" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="1.27" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-0.635" x2="-12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="-1.27" x2="-12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="1.27" x2="-18.415" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="1.27" x2="-17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="0.635" x2="-17.78" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="-0.635" x2="-18.415" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="0.635" x2="-17.145" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="1.27" x2="-15.875" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="1.27" x2="-15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="0.635" x2="-15.24" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="-0.635" x2="-15.875" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="-1.27" x2="-17.145" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="-1.27" x2="-17.78" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="0.635" x2="-20.32" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="1.27" x2="-20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="-0.635" x2="-19.685" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="-1.27" x2="-19.685" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="17.78" y1="0.635" x2="18.415" y2="1.27" width="0.1524" layer="21"/>
<wire x1="18.415" y1="1.27" x2="19.685" y2="1.27" width="0.1524" layer="21"/>
<wire x1="19.685" y1="1.27" x2="20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="20.32" y1="0.635" x2="20.32" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-0.635" x2="19.685" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="19.685" y1="-1.27" x2="18.415" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="18.415" y1="-1.27" x2="17.78" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-19.05" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-16.51" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-13.97" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-11.43" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="9" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="10" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="11" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="12" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="13" x="11.43" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="14" x="13.97" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="15" x="16.51" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="16" x="19.05" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-20.3962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-20.32" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="16.256" y1="-0.254" x2="16.764" y2="0.254" layer="51"/>
<rectangle x1="13.716" y1="-0.254" x2="14.224" y2="0.254" layer="51"/>
<rectangle x1="11.176" y1="-0.254" x2="11.684" y2="0.254" layer="51"/>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="-11.684" y1="-0.254" x2="-11.176" y2="0.254" layer="51"/>
<rectangle x1="-14.224" y1="-0.254" x2="-13.716" y2="0.254" layer="51"/>
<rectangle x1="-16.764" y1="-0.254" x2="-16.256" y2="0.254" layer="51"/>
<rectangle x1="-19.304" y1="-0.254" x2="-18.796" y2="0.254" layer="51"/>
<rectangle x1="18.796" y1="-0.254" x2="19.304" y2="0.254" layer="51"/>
</package>
<package name="1X16/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-20.32" y1="-1.905" x2="-17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="-1.905" x2="-17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="0.635" x2="-20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="0.635" x2="-20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="6.985" x2="-19.05" y2="1.27" width="0.762" layer="21"/>
<wire x1="-17.78" y1="-1.905" x2="-15.24" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="0.635" x2="-17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="6.985" x2="-16.51" y2="1.27" width="0.762" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-13.97" y1="6.985" x2="-13.97" y2="1.27" width="0.762" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="6.985" x2="-11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="11.43" y1="6.985" x2="11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="15.24" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="15.24" y1="-1.905" x2="15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="15.24" y1="0.635" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="13.97" y1="6.985" x2="13.97" y2="1.27" width="0.762" layer="21"/>
<wire x1="15.24" y1="-1.905" x2="17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="17.78" y1="-1.905" x2="17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="17.78" y1="0.635" x2="15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="16.51" y1="6.985" x2="16.51" y2="1.27" width="0.762" layer="21"/>
<wire x1="17.78" y1="-1.905" x2="20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-1.905" x2="20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="20.32" y1="0.635" x2="17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="19.05" y1="6.985" x2="19.05" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-19.05" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-16.51" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-13.97" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-11.43" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="-6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="-3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="9" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="10" x="3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="11" x="6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="12" x="8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="13" x="11.43" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="14" x="13.97" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="15" x="16.51" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="16" x="19.05" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-20.955" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="22.225" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-19.431" y1="0.635" x2="-18.669" y2="1.143" layer="21"/>
<rectangle x1="-16.891" y1="0.635" x2="-16.129" y2="1.143" layer="21"/>
<rectangle x1="-14.351" y1="0.635" x2="-13.589" y2="1.143" layer="21"/>
<rectangle x1="-11.811" y1="0.635" x2="-11.049" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="11.049" y1="0.635" x2="11.811" y2="1.143" layer="21"/>
<rectangle x1="13.589" y1="0.635" x2="14.351" y2="1.143" layer="21"/>
<rectangle x1="16.129" y1="0.635" x2="16.891" y2="1.143" layer="21"/>
<rectangle x1="18.669" y1="0.635" x2="19.431" y2="1.143" layer="21"/>
<rectangle x1="-19.431" y1="-2.921" x2="-18.669" y2="-1.905" layer="21"/>
<rectangle x1="-16.891" y1="-2.921" x2="-16.129" y2="-1.905" layer="21"/>
<rectangle x1="-14.351" y1="-2.921" x2="-13.589" y2="-1.905" layer="21"/>
<rectangle x1="-11.811" y1="-2.921" x2="-11.049" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="11.049" y1="-2.921" x2="11.811" y2="-1.905" layer="21"/>
<rectangle x1="13.589" y1="-2.921" x2="14.351" y2="-1.905" layer="21"/>
<rectangle x1="16.129" y1="-2.921" x2="16.891" y2="-1.905" layer="21"/>
<rectangle x1="18.669" y1="-2.921" x2="19.431" y2="-1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PINHD16">
<wire x1="-6.35" y1="-22.86" x2="1.27" y2="-22.86" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-22.86" x2="1.27" y2="20.32" width="0.4064" layer="94"/>
<wire x1="1.27" y1="20.32" x2="-6.35" y2="20.32" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="20.32" x2="-6.35" y2="-22.86" width="0.4064" layer="94"/>
<text x="-6.35" y="20.955" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-25.4" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="17.78" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="15.24" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="12.7" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="7" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="9" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="11" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="13" x="-2.54" y="-12.7" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="-2.54" y="-15.24" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="15" x="-2.54" y="-17.78" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="-2.54" y="-20.32" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X16" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD16" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X16">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X16/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="stm32" deviceset="STM32F10XRXT6" device=""/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X16" device=""/>
<part name="JP2" library="pinhead" deviceset="PINHD-1X16" device=""/>
<part name="JP3" library="pinhead" deviceset="PINHD-1X16" device=""/>
<part name="JP4" library="pinhead" deviceset="PINHD-1X16" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U1" gate="PORTA_L" x="30.48" y="60.96"/>
<instance part="U1" gate="PORTA_H" x="30.48" y="30.48"/>
<instance part="U1" gate="PORTB_L" x="48.26" y="58.42"/>
<instance part="U1" gate="PORTB_H" x="48.26" y="33.02"/>
<instance part="U1" gate="PORTC_L" x="33.02" y="2.54"/>
<instance part="U1" gate="PORTC_H" x="33.02" y="-22.86"/>
<instance part="U1" gate="POWER" x="33.02" y="-63.5"/>
<instance part="U1" gate="PORTD/OSC" x="48.26" y="10.16"/>
<instance part="U1" gate="AN_POWER" x="48.26" y="-5.08"/>
<instance part="U1" gate="RESET" x="48.26" y="-22.86"/>
<instance part="JP1" gate="A" x="99.06" y="-88.9" rot="R180"/>
<instance part="JP2" gate="A" x="99.06" y="-38.1" rot="R180"/>
<instance part="JP3" gate="A" x="99.06" y="12.7" rot="R180"/>
<instance part="JP4" gate="A" x="99.06" y="63.5" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="VSS" class="0">
<segment>
<pinref part="U1" gate="POWER" pin="VSS_1"/>
<wire x1="22.86" y1="-68.58" x2="20.32" y2="-68.58" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VSS_4"/>
<wire x1="20.32" y1="-68.58" x2="15.24" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-83.82" x2="20.32" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-83.82" x2="20.32" y2="-78.74" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VSS_2"/>
<wire x1="20.32" y1="-78.74" x2="20.32" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-73.66" x2="20.32" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-73.66" x2="20.32" y2="-73.66" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VSS_3"/>
<wire x1="22.86" y1="-78.74" x2="20.32" y2="-78.74" width="0.1524" layer="91"/>
<label x="2.54" y="-68.58" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="AN_POWER" pin="VSSA"/>
<wire x1="58.42" y1="-10.16" x2="66.04" y2="-10.16" width="0.1524" layer="91"/>
<label x="71.12" y="-10.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB2"/>
<wire x1="58.42" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
<label x="73.66" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="12"/>
<wire x1="101.6" y1="-78.74" x2="109.22" y2="-78.74" width="0.1524" layer="91"/>
<label x="114.3" y="-78.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="12"/>
<wire x1="101.6" y1="-27.94" x2="109.22" y2="-27.94" width="0.1524" layer="91"/>
<label x="114.3" y="-27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="2"/>
<wire x1="101.6" y1="-53.34" x2="109.22" y2="-53.34" width="0.1524" layer="91"/>
<label x="114.3" y="-53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="15"/>
<wire x1="101.6" y1="-20.32" x2="109.22" y2="-20.32" width="0.1524" layer="91"/>
<label x="114.3" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="15"/>
<wire x1="101.6" y1="30.48" x2="109.22" y2="30.48" width="0.1524" layer="91"/>
<label x="114.3" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="15"/>
<wire x1="101.6" y1="81.28" x2="109.22" y2="81.28" width="0.1524" layer="91"/>
<label x="114.3" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="VDD" class="0">
<segment>
<pinref part="U1" gate="POWER" pin="VDD_1"/>
<wire x1="22.86" y1="-43.18" x2="20.32" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VDD_4"/>
<wire x1="20.32" y1="-43.18" x2="15.24" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-58.42" x2="20.32" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-58.42" x2="20.32" y2="-53.34" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VDD_2"/>
<wire x1="20.32" y1="-53.34" x2="20.32" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-48.26" x2="20.32" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-48.26" x2="20.32" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="U1" gate="POWER" pin="VDD_3"/>
<wire x1="22.86" y1="-53.34" x2="20.32" y2="-53.34" width="0.1524" layer="91"/>
<label x="2.54" y="-43.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="AN_POWER" pin="VBAT"/>
<wire x1="58.42" y1="0" x2="63.5" y2="0" width="0.1524" layer="91"/>
<pinref part="U1" gate="AN_POWER" pin="VDDA"/>
<wire x1="63.5" y1="0" x2="66.04" y2="0" width="0.1524" layer="91"/>
<wire x1="58.42" y1="-5.08" x2="63.5" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="63.5" y1="-5.08" x2="63.5" y2="0" width="0.1524" layer="91"/>
<label x="71.12" y="0" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="101.6" y1="-106.68" x2="109.22" y2="-106.68" width="0.1524" layer="91"/>
<label x="114.3" y="-106.68" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="13"/>
<wire x1="101.6" y1="-76.2" x2="109.22" y2="-76.2" width="0.1524" layer="91"/>
<label x="114.3" y="-76.2" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="3"/>
<wire x1="101.6" y1="-50.8" x2="109.22" y2="-50.8" width="0.1524" layer="91"/>
<label x="114.3" y="-50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="16"/>
<wire x1="101.6" y1="-17.78" x2="109.22" y2="-17.78" width="0.1524" layer="91"/>
<label x="114.3" y="-17.78" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="16"/>
<wire x1="101.6" y1="33.02" x2="109.22" y2="33.02" width="0.1524" layer="91"/>
<label x="114.3" y="33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="16"/>
<wire x1="101.6" y1="83.82" x2="109.22" y2="83.82" width="0.1524" layer="91"/>
<label x="114.3" y="83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="P14" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA0"/>
<wire x1="22.86" y1="68.58" x2="15.24" y2="68.58" width="0.1524" layer="91"/>
<label x="10.16" y="68.58" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="14"/>
<wire x1="101.6" y1="-73.66" x2="109.22" y2="-73.66" width="0.1524" layer="91"/>
<label x="109.22" y="-73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="P15" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA1"/>
<wire x1="22.86" y1="66.04" x2="15.24" y2="66.04" width="0.1524" layer="91"/>
<label x="10.16" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="15"/>
<wire x1="101.6" y1="-71.12" x2="109.22" y2="-71.12" width="0.1524" layer="91"/>
<label x="109.22" y="-71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="P16" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA2"/>
<wire x1="22.86" y1="63.5" x2="15.24" y2="63.5" width="0.1524" layer="91"/>
<label x="10.16" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="16"/>
<wire x1="101.6" y1="-68.58" x2="109.22" y2="-68.58" width="0.1524" layer="91"/>
<label x="109.22" y="-68.58" size="1.778" layer="95"/>
</segment>
</net>
<net name="P17" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA3"/>
<wire x1="22.86" y1="60.96" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
<label x="10.16" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="1"/>
<wire x1="101.6" y1="-55.88" x2="109.22" y2="-55.88" width="0.1524" layer="91"/>
<label x="109.22" y="-55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="P20" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA4"/>
<wire x1="22.86" y1="58.42" x2="15.24" y2="58.42" width="0.1524" layer="91"/>
<label x="10.16" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="4"/>
<wire x1="101.6" y1="-48.26" x2="109.22" y2="-48.26" width="0.1524" layer="91"/>
<label x="109.22" y="-48.26" size="1.778" layer="95"/>
</segment>
</net>
<net name="P21" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA5"/>
<wire x1="22.86" y1="55.88" x2="15.24" y2="55.88" width="0.1524" layer="91"/>
<label x="10.16" y="55.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="5"/>
<wire x1="101.6" y1="-45.72" x2="109.22" y2="-45.72" width="0.1524" layer="91"/>
<label x="109.22" y="-45.72" size="1.778" layer="95"/>
</segment>
</net>
<net name="P22" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA6"/>
<wire x1="22.86" y1="53.34" x2="15.24" y2="53.34" width="0.1524" layer="91"/>
<label x="10.16" y="53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="6"/>
<wire x1="101.6" y1="-43.18" x2="109.22" y2="-43.18" width="0.1524" layer="91"/>
<label x="109.22" y="-43.18" size="1.778" layer="95"/>
</segment>
</net>
<net name="P23" class="0">
<segment>
<pinref part="U1" gate="PORTA_L" pin="PA7"/>
<wire x1="22.86" y1="50.8" x2="15.24" y2="50.8" width="0.1524" layer="91"/>
<label x="10.16" y="50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="7"/>
<wire x1="101.6" y1="-40.64" x2="109.22" y2="-40.64" width="0.1524" layer="91"/>
<label x="109.22" y="-40.64" size="1.778" layer="95"/>
</segment>
</net>
<net name="P41" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA8"/>
<wire x1="22.86" y1="40.64" x2="15.24" y2="40.64" width="0.1524" layer="91"/>
<label x="10.16" y="40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="9"/>
<wire x1="101.6" y1="15.24" x2="109.22" y2="15.24" width="0.1524" layer="91"/>
<label x="109.22" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="P42" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA9"/>
<wire x1="22.86" y1="38.1" x2="15.24" y2="38.1" width="0.1524" layer="91"/>
<label x="10.16" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="10"/>
<wire x1="101.6" y1="17.78" x2="109.22" y2="17.78" width="0.1524" layer="91"/>
<label x="109.22" y="17.78" size="1.778" layer="95"/>
</segment>
</net>
<net name="P43" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA10"/>
<wire x1="22.86" y1="35.56" x2="15.24" y2="35.56" width="0.1524" layer="91"/>
<label x="10.16" y="35.56" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="11"/>
<wire x1="101.6" y1="20.32" x2="109.22" y2="20.32" width="0.1524" layer="91"/>
<label x="109.22" y="20.32" size="1.778" layer="95"/>
</segment>
</net>
<net name="P44" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA11"/>
<wire x1="22.86" y1="33.02" x2="15.24" y2="33.02" width="0.1524" layer="91"/>
<label x="10.16" y="33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="12"/>
<wire x1="101.6" y1="22.86" x2="109.22" y2="22.86" width="0.1524" layer="91"/>
<label x="109.22" y="22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="P45" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA12"/>
<wire x1="22.86" y1="30.48" x2="15.24" y2="30.48" width="0.1524" layer="91"/>
<label x="10.16" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="13"/>
<wire x1="101.6" y1="25.4" x2="109.22" y2="25.4" width="0.1524" layer="91"/>
<label x="109.22" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="P46" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA13"/>
<wire x1="22.86" y1="27.94" x2="15.24" y2="27.94" width="0.1524" layer="91"/>
<label x="10.16" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="14"/>
<wire x1="101.6" y1="27.94" x2="109.22" y2="27.94" width="0.1524" layer="91"/>
<label x="109.22" y="27.94" size="1.778" layer="95"/>
</segment>
</net>
<net name="P49" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA14"/>
<wire x1="22.86" y1="25.4" x2="15.24" y2="25.4" width="0.1524" layer="91"/>
<label x="10.16" y="25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="1"/>
<wire x1="101.6" y1="45.72" x2="109.22" y2="45.72" width="0.1524" layer="91"/>
<label x="109.22" y="45.72" size="1.778" layer="95"/>
</segment>
</net>
<net name="P50" class="0">
<segment>
<pinref part="U1" gate="PORTA_H" pin="PA15"/>
<wire x1="22.86" y1="22.86" x2="15.24" y2="22.86" width="0.1524" layer="91"/>
<label x="10.16" y="22.86" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="2"/>
<wire x1="101.6" y1="48.26" x2="109.22" y2="48.26" width="0.1524" layer="91"/>
<label x="109.22" y="48.26" size="1.778" layer="95"/>
</segment>
</net>
<net name="P8" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC0"/>
<wire x1="22.86" y1="12.7" x2="15.24" y2="12.7" width="0.1524" layer="91"/>
<label x="10.16" y="12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="8"/>
<wire x1="101.6" y1="-88.9" x2="109.22" y2="-88.9" width="0.1524" layer="91"/>
<label x="109.22" y="-88.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="P9" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC1"/>
<wire x1="22.86" y1="10.16" x2="15.24" y2="10.16" width="0.1524" layer="91"/>
<label x="10.16" y="10.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="9"/>
<wire x1="101.6" y1="-86.36" x2="109.22" y2="-86.36" width="0.1524" layer="91"/>
<label x="109.22" y="-86.36" size="1.778" layer="95"/>
</segment>
</net>
<net name="P10" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC2"/>
<wire x1="22.86" y1="7.62" x2="15.24" y2="7.62" width="0.1524" layer="91"/>
<label x="10.16" y="7.62" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="10"/>
<wire x1="101.6" y1="-83.82" x2="109.22" y2="-83.82" width="0.1524" layer="91"/>
<label x="109.22" y="-83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="P11" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC3"/>
<wire x1="22.86" y1="5.08" x2="15.24" y2="5.08" width="0.1524" layer="91"/>
<label x="10.16" y="5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="11"/>
<wire x1="101.6" y1="-81.28" x2="109.22" y2="-81.28" width="0.1524" layer="91"/>
<label x="109.22" y="-81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="P24" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC4"/>
<wire x1="22.86" y1="2.54" x2="15.24" y2="2.54" width="0.1524" layer="91"/>
<label x="10.16" y="2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="8"/>
<wire x1="101.6" y1="-38.1" x2="109.22" y2="-38.1" width="0.1524" layer="91"/>
<label x="109.22" y="-38.1" size="1.778" layer="95"/>
</segment>
</net>
<net name="P25" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC5"/>
<wire x1="22.86" y1="0" x2="15.24" y2="0" width="0.1524" layer="91"/>
<label x="10.16" y="0" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="9"/>
<wire x1="101.6" y1="-35.56" x2="109.22" y2="-35.56" width="0.1524" layer="91"/>
<label x="109.22" y="-35.56" size="1.778" layer="95"/>
</segment>
</net>
<net name="P37" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC6"/>
<wire x1="22.86" y1="-2.54" x2="15.24" y2="-2.54" width="0.1524" layer="91"/>
<label x="10.16" y="-2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="5"/>
<wire x1="101.6" y1="5.08" x2="109.22" y2="5.08" width="0.1524" layer="91"/>
<label x="109.22" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="P38" class="0">
<segment>
<pinref part="U1" gate="PORTC_L" pin="PC7"/>
<wire x1="22.86" y1="-5.08" x2="15.24" y2="-5.08" width="0.1524" layer="91"/>
<label x="10.16" y="-5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="6"/>
<wire x1="101.6" y1="7.62" x2="109.22" y2="7.62" width="0.1524" layer="91"/>
<label x="109.22" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="P39" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC8"/>
<wire x1="22.86" y1="-15.24" x2="15.24" y2="-15.24" width="0.1524" layer="91"/>
<label x="10.16" y="-15.24" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="7"/>
<wire x1="101.6" y1="10.16" x2="109.22" y2="10.16" width="0.1524" layer="91"/>
<label x="109.22" y="10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="P40" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC9"/>
<wire x1="22.86" y1="-17.78" x2="15.24" y2="-17.78" width="0.1524" layer="91"/>
<label x="10.16" y="-17.78" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="8"/>
<wire x1="101.6" y1="12.7" x2="109.22" y2="12.7" width="0.1524" layer="91"/>
<label x="109.22" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="P51" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC10"/>
<wire x1="22.86" y1="-20.32" x2="15.24" y2="-20.32" width="0.1524" layer="91"/>
<label x="10.16" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="3"/>
<wire x1="101.6" y1="50.8" x2="109.22" y2="50.8" width="0.1524" layer="91"/>
<label x="109.22" y="50.8" size="1.778" layer="95"/>
</segment>
</net>
<net name="P52" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC11"/>
<wire x1="22.86" y1="-22.86" x2="15.24" y2="-22.86" width="0.1524" layer="91"/>
<label x="10.16" y="-22.86" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="4"/>
<wire x1="101.6" y1="53.34" x2="109.22" y2="53.34" width="0.1524" layer="91"/>
<label x="109.22" y="53.34" size="1.778" layer="95"/>
</segment>
</net>
<net name="P53" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC12"/>
<wire x1="22.86" y1="-25.4" x2="15.24" y2="-25.4" width="0.1524" layer="91"/>
<label x="10.16" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="5"/>
<wire x1="101.6" y1="55.88" x2="109.22" y2="55.88" width="0.1524" layer="91"/>
<label x="109.22" y="55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="P2" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC13"/>
<wire x1="22.86" y1="-27.94" x2="15.24" y2="-27.94" width="0.1524" layer="91"/>
<label x="10.16" y="-27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="101.6" y1="-104.14" x2="109.22" y2="-104.14" width="0.1524" layer="91"/>
<label x="109.22" y="-104.14" size="1.778" layer="95"/>
</segment>
</net>
<net name="P3" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC14"/>
<wire x1="22.86" y1="-30.48" x2="15.24" y2="-30.48" width="0.1524" layer="91"/>
<label x="10.16" y="-30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="101.6" y1="-101.6" x2="109.22" y2="-101.6" width="0.1524" layer="91"/>
<label x="109.22" y="-101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="P4" class="0">
<segment>
<pinref part="U1" gate="PORTC_H" pin="PC15"/>
<wire x1="22.86" y1="-33.02" x2="15.24" y2="-33.02" width="0.1524" layer="91"/>
<label x="10.16" y="-33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="4"/>
<wire x1="101.6" y1="-99.06" x2="109.22" y2="-99.06" width="0.1524" layer="91"/>
<label x="109.22" y="-99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="P26" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB0"/>
<wire x1="58.42" y1="68.58" x2="63.5" y2="68.58" width="0.1524" layer="91"/>
<label x="63.5" y="68.58" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="10"/>
<wire x1="101.6" y1="-33.02" x2="109.22" y2="-33.02" width="0.1524" layer="91"/>
<label x="109.22" y="-33.02" size="1.778" layer="95"/>
</segment>
</net>
<net name="P27" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB1"/>
<wire x1="63.5" y1="66.04" x2="58.42" y2="66.04" width="0.1524" layer="91"/>
<label x="63.5" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="11"/>
<wire x1="101.6" y1="-30.48" x2="109.22" y2="-30.48" width="0.1524" layer="91"/>
<label x="109.22" y="-30.48" size="1.778" layer="95"/>
</segment>
</net>
<net name="P55" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB3"/>
<wire x1="58.42" y1="60.96" x2="63.5" y2="60.96" width="0.1524" layer="91"/>
<label x="63.5" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="7"/>
<wire x1="101.6" y1="60.96" x2="109.22" y2="60.96" width="0.1524" layer="91"/>
<label x="109.22" y="60.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="P56" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB4"/>
<wire x1="58.42" y1="58.42" x2="63.5" y2="58.42" width="0.1524" layer="91"/>
<label x="63.5" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="8"/>
<wire x1="101.6" y1="63.5" x2="109.22" y2="63.5" width="0.1524" layer="91"/>
<label x="109.22" y="63.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="P57" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB5"/>
<wire x1="58.42" y1="55.88" x2="63.5" y2="55.88" width="0.1524" layer="91"/>
<label x="63.5" y="55.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="9"/>
<wire x1="101.6" y1="66.04" x2="109.22" y2="66.04" width="0.1524" layer="91"/>
<label x="109.22" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="P58" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB6"/>
<wire x1="58.42" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
<label x="63.5" y="53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="10"/>
<wire x1="101.6" y1="68.58" x2="109.22" y2="68.58" width="0.1524" layer="91"/>
<label x="109.22" y="68.58" size="1.778" layer="95"/>
</segment>
</net>
<net name="P59" class="0">
<segment>
<pinref part="U1" gate="PORTB_L" pin="PB7"/>
<wire x1="58.42" y1="50.8" x2="60.96" y2="50.8" width="0.1524" layer="91"/>
<wire x1="58.42" y1="50.8" x2="63.5" y2="50.8" width="0.1524" layer="91"/>
<label x="63.5" y="50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="11"/>
<wire x1="101.6" y1="71.12" x2="109.22" y2="71.12" width="0.1524" layer="91"/>
<label x="109.22" y="71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="P61" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB8"/>
<wire x1="58.42" y1="40.64" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
<label x="63.5" y="40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="13"/>
<wire x1="101.6" y1="76.2" x2="109.22" y2="76.2" width="0.1524" layer="91"/>
<label x="109.22" y="76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="P62" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB9"/>
<wire x1="58.42" y1="38.1" x2="63.5" y2="38.1" width="0.1524" layer="91"/>
<label x="63.5" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="14"/>
<wire x1="101.6" y1="78.74" x2="109.22" y2="78.74" width="0.1524" layer="91"/>
<label x="109.22" y="78.74" size="1.778" layer="95"/>
</segment>
</net>
<net name="P29" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB10"/>
<wire x1="58.42" y1="35.56" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
<label x="63.5" y="35.56" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="13"/>
<wire x1="101.6" y1="-25.4" x2="109.22" y2="-25.4" width="0.1524" layer="91"/>
<label x="109.22" y="-25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="P30" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB11"/>
<wire x1="58.42" y1="33.02" x2="63.5" y2="33.02" width="0.1524" layer="91"/>
<label x="63.5" y="33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="14"/>
<wire x1="101.6" y1="-22.86" x2="109.22" y2="-22.86" width="0.1524" layer="91"/>
<label x="109.22" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="P33" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB12"/>
<wire x1="58.42" y1="30.48" x2="63.5" y2="30.48" width="0.1524" layer="91"/>
<label x="63.5" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="1"/>
<wire x1="101.6" y1="-5.08" x2="109.22" y2="-5.08" width="0.1524" layer="91"/>
<label x="109.22" y="-5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="P34" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB13"/>
<wire x1="58.42" y1="27.94" x2="63.5" y2="27.94" width="0.1524" layer="91"/>
<label x="63.5" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="2"/>
<wire x1="101.6" y1="-2.54" x2="109.22" y2="-2.54" width="0.1524" layer="91"/>
<label x="109.22" y="-2.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="P35" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB14"/>
<wire x1="58.42" y1="25.4" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
<label x="63.5" y="25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="3"/>
<wire x1="101.6" y1="0" x2="109.22" y2="0" width="0.1524" layer="91"/>
<label x="109.22" y="0" size="1.778" layer="95"/>
</segment>
</net>
<net name="P36" class="0">
<segment>
<pinref part="U1" gate="PORTB_H" pin="PB15"/>
<wire x1="58.42" y1="22.86" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<label x="63.5" y="22.86" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="4"/>
<wire x1="101.6" y1="2.54" x2="109.22" y2="2.54" width="0.1524" layer="91"/>
<label x="109.22" y="2.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="P5" class="0">
<segment>
<pinref part="U1" gate="PORTD/OSC" pin="PD0/OSC&lt;="/>
<wire x1="58.42" y1="12.7" x2="63.5" y2="12.7" width="0.1524" layer="91"/>
<label x="63.5" y="12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="101.6" y1="-96.52" x2="109.22" y2="-96.52" width="0.1524" layer="91"/>
<label x="109.22" y="-96.52" size="1.778" layer="95"/>
</segment>
</net>
<net name="P6" class="0">
<segment>
<pinref part="U1" gate="PORTD/OSC" pin="PD1/OSC=&gt;"/>
<wire x1="58.42" y1="10.16" x2="63.5" y2="10.16" width="0.1524" layer="91"/>
<label x="63.5" y="10.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="6"/>
<wire x1="101.6" y1="-93.98" x2="109.22" y2="-93.98" width="0.1524" layer="91"/>
<label x="109.22" y="-93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="P54" class="0">
<segment>
<pinref part="U1" gate="PORTD/OSC" pin="PD2"/>
<wire x1="58.42" y1="7.62" x2="63.5" y2="7.62" width="0.1524" layer="91"/>
<label x="63.5" y="7.62" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="6"/>
<wire x1="101.6" y1="58.42" x2="109.22" y2="58.42" width="0.1524" layer="91"/>
<label x="109.22" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="NRST" class="0">
<segment>
<pinref part="U1" gate="RESET" pin="NRST"/>
<wire x1="58.42" y1="-20.32" x2="63.5" y2="-20.32" width="0.1524" layer="91"/>
<label x="71.12" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="7"/>
<wire x1="101.6" y1="-91.44" x2="109.22" y2="-91.44" width="0.1524" layer="91"/>
<label x="114.3" y="-91.44" size="1.778" layer="95"/>
</segment>
</net>
<net name="BOOT0" class="0">
<segment>
<pinref part="U1" gate="RESET" pin="BOOT0"/>
<wire x1="58.42" y1="-25.4" x2="63.5" y2="-25.4" width="0.1524" layer="91"/>
<label x="71.12" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="12"/>
<wire x1="101.6" y1="73.66" x2="109.22" y2="73.66" width="0.1524" layer="91"/>
<label x="114.3" y="73.66" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
