
# MSC_Tests.ttcn

* external interfaces
    * A: BSSAP/SCCP/M3UA (emulates BSC-side)
    * MNCC: MNCC/unix-domain (emulates ext. MNCC side)
    * MGW: MGCP (emulates MGW side)
    * GSUP (impllements HLR side)

{% dot msc_tests.svg
digraph G {
  rankdir=LR;
  MSC [label="IUT\nosmo-msc",shape="box"];
  ATS [label="ATS\nMSC_Tests.ttcn"];

  ATS -> MSC [label="MNCC"];
  ATS -> MSC [label="SMPP",style="dashed"];
  ATS -> MSC [label="CTRL"];
  ATS -> MSC [label="VTY"];
  MSC -> ATS [label="GSUP"];
  ATS -> STP [label="A BSSAP\nSCCP/M3UA"];
  MSC -> STP [label="A BSSAP\nSCCP/M3UA"];
}
%}
