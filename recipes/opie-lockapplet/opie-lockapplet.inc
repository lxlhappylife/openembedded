DESCRIPTION = "Lock Opie now Button to lock Opie (as configured in the Security settings) on demand."
SECTION = "opie/applets"
PRIORITY = "optional"
LICENSE = "GPL"
APPNAME = "lockapplet"
DEPENDS = "opie-security"
RDEPENDS_${PN} = "opie-security"


S = "${WORKDIR}/lockapplet"

inherit opie

pkg_postinst() {
#!/bin/sh
if [ -n "$D" ]; then exit 1; fi
if pidof -s qpe >/dev/null; then
  ${bindir}/qcop QPE/TaskBar "reloadApplets()"
fi
}

pkg_postrm() {
#!/bin/sh
${bindir}/qcop QPE/TaskBar "reloadApplets()"
 if [ -n "$D" ]; then false; fi
}

do_install() {
    install -d ${D}${palmtopdir}/plugins/applets ${D}${palmtopdir}/pics/security/
    oe_libinstall -so liblockapplet ${D}${palmtopdir}/plugins/applets/
}

