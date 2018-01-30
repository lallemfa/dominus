MAINTAINERCLEANFILES = Makefile.in domoticz_side relay_side

bin_PROGRAMS = domoticz_side relay_side

domoticz_side_SOURCES = domoticz_side.c
domoticz_side_LDADD = ../libs/libgpio_set.la ../libs/libserver_client.la

relay_side_SOURCES = relay_side.c
relay_side_LDADD = ../libs/libgpio_set.la ../libs/libserver_host.la