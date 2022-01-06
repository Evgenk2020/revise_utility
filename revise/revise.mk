################################################################################
#
# revise
#
################################################################################

REVISE_VERSION = 1.0
REVISE_SITE = ./package/revise/src
REVISE_SITE_METHOD = local
REVISE_INSTALL_STAGING = NO
LIBFOO_INSTALL_TARGET = YES
REVISE_DEPENDENCIES = libcurl

$(eval $(cmake-package))
