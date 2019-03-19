
ECLIPSEGIT:=https://github.com/eclipse
ECLIPSEGIT2:=git://git.eclipse.org/gitroot/titan
OSMOGITHUB:=https://github.com/osmocom
OSMOGIT:=git://git.osmocom.org

ECLIPSEGIT_REPOS= titan.Libraries.TCCUsefulFunctions \
			titan.ProtocolModules.IP \
			titan.ProtocolModules.TCP \
			titan.ProtocolModules.UDP \
			titan.ProtocolModules.RTP \
			titan.TestPorts.Common_Components.Socket-API \
			titan.TestPorts.IPL4asp \
			titan.TestPorts.SIPmsg \
			titan.TestPorts.TCPasp \
			titan.TestPorts.TELNETasp \
			titan.TestPorts.UDPasp \
			titan.TestPorts.UNIX_DOMAIN_SOCKETasp

ECLIPSEGIT2_REPOS= titan.ProtocolModules.ROSE \
			titan.ProtocolModules.SDP \
			titan.ProtocolModules.MobileL3_v13.4.0

OSMOGIT_REPOS= titan.ProtocolModules.MAP

ALL_REPOS=$(ECLIPSEGIT_REPOS) $(ECLIPSEGIT2_REPOS) $(OSMOGIT_REPOS)

# Tag names from 'git-describe --tags'; if not available, a commit hash may be used instead.
# In order to keep local changes in the repository of a dependency, set its commit to the
# name of a local branch here (e.g. 'master').
titan.Libraries.TCCUsefulFunctions_commit=	R.30.A
titan.ProtocolModules.IP_commit=		R.10.B-1-g99d0ec9
titan.ProtocolModules.MAP_commit=		R.2.A-1-g79c6a3d
titan.ProtocolModules.MobileL3_v13.4.0_commit=	R.2.A
titan.ProtocolModules.RTP_commit=		R.5.A
titan.ProtocolModules.ROSE_commit=		R.1.C
titan.ProtocolModules.SDP_commit=		R.14.A
titan.ProtocolModules.TCP_commit=		R.3.A
titan.ProtocolModules.UDP_commit=		R.4.A
titan.TestPorts.Common_Components.Socket-API_commit=	R.6.A
titan.TestPorts.IPL4asp_commit=			R.29.A
titan.TestPorts.SIPmsg_commit=			R.15.A-1-ge4f9dd0
titan.TestPorts.TCPasp_commit=			R.9.A
titan.TestPorts.TELNETasp_commit=		R.9.A
titan.TestPorts.UDPasp_commit=			R.8.A
titan.TestPorts.UNIX_DOMAIN_SOCKETasp_commit=	R.2.A-4-gbacd73d

all: $(foreach dir,$(ALL_REPOS),$(dir)/update)
clean: $(foreach dir,$(ALL_REPOS),$(dir)/clean)
distclean: $(foreach dir,$(ALL_REPOS),$(dir)/distclean)

define GIT_template
$(1)_ORIGIN!=	if [ -d $(1) ]; then cd $(1) && git remote get-url origin; fi
$(1)_HEAD!=	if [ -d $(1) ]; then cd $(1) && git describe --tags 2>/dev/null || git rev-parse HEAD; fi
$(1)_MODIFIED!=	if [ -d $(1) ]; then cd $(1) && git diff --quiet --exit-code || echo -n "1"; fi

$(1):
	git clone $(2)/$(1)

.PHONY: $(1)/update
$(1)/update: $(1)
ifeq ($$($(1)_MODIFIED),1)
	@echo "WARNING: $(1) skipped because it contains uncommitted modifications!"
else
ifneq ($$($(1)_ORIGIN),$(2)/$(1))
	cd $(1) && git remote set-url origin $(2)/$(1) && git fetch
endif
ifneq ($$($(1)_HEAD),$($(1)_commit))
	cd $(1) && git fetch && git checkout -q -f "$($(1)_commit)"
endif
endif

.PHONY: $(1)/clean
$(1)/clean: $(1)
ifeq ($$($(1)_MODIFIED),1)
	@echo "WARNING: $(1) skipped because it contains uncommitted modifications!"
else
	cd $(1) && git fetch && git checkout -q -f "$($(1)_commit)" && git reset --hard
endif

.PHONY: $(1)/distclean
$(1)/distclean:
ifeq ($$($(1)_MODIFIED),1)
	@echo "WARNING: $(1) skipped because it contains uncommitted modifications!"
else
	@rm -rf $(1)
endif
endef

$(foreach dir,$(ECLIPSEGIT_REPOS), \
	$(eval $(call GIT_template,$(dir),$(ECLIPSEGIT))))

$(foreach dir,$(ECLIPSEGIT2_REPOS), \
	$(eval $(call GIT_template,$(dir),$(ECLIPSEGIT2))))

$(foreach dir,$(OSMOGIT_REPOS), \
	$(eval $(call GIT_template,$(dir),$(OSMOGIT))))
