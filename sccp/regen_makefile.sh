#!/bin/sh

FILES="*.ttcn *.ttcnpp SCCP_EncDec.cc  SCTPasp_PT.cc  TCCConversion.cc TCCInterface.cc UD_PT.cc IPL4asp_PT.cc IPL4asp_discovery.cc IPA_CodecPort_CtrlFunctDef.cc TELNETasp_PT.cc Native_FunctionDefs.cc TCCEncoding.cc "

export CPPFLAGS_TTCN3="-DIPA_EMULATION_SCCP -DUSE_MTP3_DISTRIBUTOR"

../regen-makefile.sh SCCP_Tests.ttcn $FILES
