/*
 *	Configuration Library by Parra Studios
 *	Copyright (C) 2016 - 2017 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	A cross-platform library for managing multiple configuration formats.
 *
 */

#ifndef CONFIGURATION_INTERFACE_H
#define CONFIGURATION_INTERFACE_H 1

/* -- Headers -- */

#include <configuration/configuration_api.h>

#include <configuration/configuration_object.h>
#include <configuration/configuration_impl_handle.h>

#include <adt/adt_vector.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -- Forward Declarations -- */

struct configuration_interface_type;

/* -- Type Definitions -- */

typedef const char * (*configuration_interface_extension)(void);

typedef int (*configuration_interface_initialize)(void);

typedef configuration_impl (*configuration_interface_load)(configuration);

typedef int (*configuration_interface_unload)(configuration);

typedef int (*configuration_interface_destroy)(void);

typedef struct configuration_interface_type * configuration_interface;

typedef configuration_interface (*configuration_interface_singleton)(void);

/* -- Member Data -- */

struct configuration_interface_type
{
	configuration_interface_extension extension;
	configuration_interface_initialize initialize;
	configuration_interface_load load;
	configuration_interface_unload unload;
	configuration_interface_destroy destroy;
};

#ifdef __cplusplus
}
#endif

#endif /* CONFIGURATION_INTERFACE_H */