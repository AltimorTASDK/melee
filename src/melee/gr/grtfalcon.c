#include <melee/gr/grtfalcon.h>

static StageCallbacks lbl_803E8608[4] = {
    {
        lbl_8021FDEC,
        lbl_8021FE18,
        lbl_8021FE20,
        lbl_8021FE24,
        0UL
    }, {
        lbl_8021FEB8,
        lbl_8021FF08,
        lbl_8021FF10,
        lbl_8021FF30,
        0UL
    }, {
        lbl_8021FE28,
        lbl_8021FE78,
        lbl_8021FE80,
        lbl_8021FEB4,
        0xC0000000
    }, {
        NULL,
        NULL,
        NULL,
        NULL,
        0UL
    }
};

extern StageData lbl_803E8664 = {
    0x00000029,
    lbl_803E8608,
    "/GrTCa.dat",
	lbl_8021FC64,
	func_8021FC60,
	lbl_8021FCD4,
	lbl_8021FCD8,
	lbl_8021FCFC,
	lbl_8021FF34,
	lbl_8021FF3C,
    0x00000001,
    NULL,
    0UL
};

extern StageInfo stage_info;

static void func_8021FC60(long){}
static void lbl_8021FC64(void) {
    stage_info.unk8C.b4 = 0;
    stage_info.unk8C.b5 = 1;
    func_8021FD04(0);
    func_8021FD04(1);
    func_8021FD04(2);
    func_801C39C0();
    func_801C3BB4();
    func_801C4210();
    func_801C42AC();
}
static void lbl_8021FCD4(void){}
static void lbl_8021FCD8(void) {
    func_801CAE04(0);
}
static s32 lbl_8021FCFC(void) {
    return 0;
}
static HSD_GObj* func_8021FD04(s32 gobj_id){
    HSD_GObj* gobj;
    StageCallbacks* callbacks = &lbl_803E8608[gobj_id];

    gobj = func_801C14D0(gobj_id);
    if (gobj != NULL) {
        Map* map = gobj->user_data;
        map->x8_callback = NULL;
        map->xC_callback = NULL;
        GObj_SetupGXLink(gobj, func_801C5DB0, 3, 0);
        if (callbacks->callback3 != NULL) {
            map->x1C_callback = callbacks->callback3;
        }
        if (callbacks->callback0 != NULL) {
            callbacks->callback0(gobj);
        }
        if (callbacks->callback2 != NULL) {
            func_8038FD54(gobj, callbacks->callback2, 4);
        }
    } else {
        OSReport("%s:%d: couldn t get gobj(id=%d)\n", "grtcaptain.c", 0xd7, gobj_id);
    }

    return gobj;
}
static void lbl_8021FDEC(HSD_GObj* gobj) {
    Map* map = gobj->user_data;
    func_801C8138(gobj, map->map_id, 0);
}
static s32 lbl_8021FE18(void) {
    return 0;
}
static void lbl_8021FE20(HSD_GObj*){}
static void lbl_8021FE24(void){}
static void lbl_8021FE28(HSD_GObj* gobj) {
    u32 unused[2];
    Map* map = gobj->user_data;
    func_801C2ED0(gobj->hsd_obj, map->map_id);
    func_801C8138(gobj, map->map_id, 0);
}
static s32 lbl_8021FE78(void) {
    return 0;
}
static void lbl_8021FE80(HSD_GObj* gobj) {
    func_800115F4();
    func_801C2FE0(gobj);
}
static void lbl_8021FEB4(void){}
static void lbl_8021FEB8(HSD_GObj* gobj) {
    u32 unused[2];
    Map* map = gobj->user_data;
    func_801C2ED0(gobj->hsd_obj, map->map_id);
    func_801C8138(gobj, map->map_id, 0);
}
static s32 lbl_8021FF08(void) {
    return 0;
}
static void lbl_8021FF10(HSD_GObj*) {
    func_801C2FE0();
}
static void lbl_8021FF30(void){}
static int lbl_8021FF34(long) {
    return 0;
}
static s32 lbl_8021FF3C(Vec*, s32, struct _HSD_JObj *) {
    return 1;
}