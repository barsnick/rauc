#pragma once

#include <glib.h>

typedef struct {
	GChecksumType type;
	gchar *digest;
} RaucChecksum;

typedef struct {
	gchar *system_compatible;
	gchar *system_bootloader;

	gchar *keyring_path;

	GHashTable *slots;
} RaucConfig;

typedef struct _RaucSlot {
	gchar *name;
	gchar *device;
	gchar *type;
	gchar *bootname;
	gboolean readonly;
	struct _RaucSlot *parent;
} RaucSlot;

typedef struct {
	gchar *system_compatible;

} RaucManifest;

typedef struct {
	gchar *status;
	RaucChecksum checksum;
} RaucSlotStatus;

gboolean load_config(const gchar *filename, RaucConfig **config);
void free_config(RaucConfig *config);

gboolean load_manifest(const gchar *filename, RaucManifest **manifest);
void free_manifest(RaucManifest *manifest);

gboolean load_slot_status(const gchar *filename, RaucSlotStatus **slotstatus);
void free_slot_status(RaucSlotStatus *slotstatus);