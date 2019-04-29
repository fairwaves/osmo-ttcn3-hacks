# osmo-ttcn3-hacks

To start your osmo-ttcn tests:

#### First console
* git clone https://github.com/fairwaves/gsup-sip-translation-agent.git
* git checkout develop
* make compile
* make run

#### Second console
* git clone https://github.com/fairwaves/osmo-ttcn3-hacks.git
* git checkout develop
* apt install eclipse-titan
* cd osmo-ttc3-hacks/deps && make
* cd ../hlr
* ./gen_links.sh
* ./regen_makefile.sh
* make compile
* make -j5
* sudo ../start-testsuite.sh HLR_Tests HLR_Tests.cfg
