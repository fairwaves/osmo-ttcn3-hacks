#!/bin/sh

FILES="*.ttcn *.ttcnpp SCCP_EncDec.cc  SCTPasp_PT.cc  TCCConversion.cc TCCInterface.cc UD_PT.cc MNCC_EncDec.cc IPL4asp_PT.cc IPL4asp_discovery.cc SDP_EncDec.cc RTP_EncDec.cc IPA_CodecPort_CtrlFunctDef.cc RTP_CodecPort_CtrlFunctDef.cc MGCP_CodecPort_CtrlFunctDef.cc TELNETasp_PT.cc Native_FunctionDefs.cc SMPP_EncDec.cc *.c"

export CPPFLAGS_TTCN3="-DIPA_EMULATION_MGCP -DIPA_EMULATION_GSUP -DUSE_MTP3_DISTRIBUTOR"

../regen-makefile.sh MSC_Tests.ttcn $FILES
