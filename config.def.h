/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx          = 3;        /* border pixel of windows */
static const unsigned int snap              = 32;       /* snap pixel */
static const unsigned int gappih            = 6;       /* horiz inner gap between windows */
static const unsigned int gappiv            = 6;       /* vert inner gap between windows */
static const unsigned int gappoh            = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov            = 6;       /* vert outer gap between windows and screen edge */
static const int smartgaps                  = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar                    = 1;        /* 0 means no bar */
static const int topbar                     = 1;        /* 0 means bottom bar */
static const int user_bh                    = 10;        /* 2 is the default spacing around the bar's font */
// static const char *fonts[]                  = { "JetBrainsMono Nerd Font Mono:style:medium:pixelsize=18" };
static const char *fonts[]                  = { "FiraCode Medium:pixelsize=19:antialias=true:autohint=true" };
static const char dmenufont[]               = "FiraCode Medium:pixelsize=19:antialias=true:autohint=true";
/* colors catppuccin-frappe */
static const char rosewater[]               = "#f2d5cf";
static const char flamingo[]                = "#eebebe";
static const char pink[]                    = "#f4b8e4";
static const char mauve[]                   = "#ca9ee6";
static const char red[]                     = "#e78284";
static const char maroon[]                  = "#ea999c";
static const char peach[]                   = "#ef9f76";
static const char yellow[]                  = "#e5c890";
static const char green[]                   = "#a6d189";
static const char teal[]                    = "#81c8be";
static const char sky[]                     = "#99d1db";
static const char sapphire[]                = "#85c1dc";
static const char blue[]                    = "#8caaee";
static const char lavender[]                = "#babbf1";
static const char text[]                    = "#c6d0f5";
static const char subtext1[]                = "#b5bfe2";
static const char subtext0[]                = "#a5adce";
static const char overlay2[]                = "#949cbb";
static const char overlay1[]                = "#838ba7";
static const char overlay0[]                = "#737994";
static const char surface2[]                = "#626880";
static const char surface1[]                = "#51576d";
static const char surface0[]                = "#414559";
static const char base[]                    = "#303446";
static const char mantle[]                  = "#292c3c";
static const char crust[]                   = "#232634";

static const char *colors[][3] = {
    /*                    fg     bg      border */
    [SchemeNorm]      = { text, base,     mantle   },
    [SchemeSel]       = { text, surface0, subtext0 },
    [SchemeHid]       = { text, base,     base     },
    [SchemeStatus]    = { text, base,     base     }, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel]   = { base, lavender, base     }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { text, base,     base     }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]   = { text, base,     base     }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { text, base,     base     }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class                            instance    title       tags mask     isfloating   monitor */
    { "Gimp",                           NULL,       NULL,       1 << 3,       0,           -1 },
    { "firefox",                        NULL,       NULL,       1 << 1,       0,           -1 },
    { "Chromium",                       NULL,       NULL,       1 << 1,       0,           -1 },
    { "Microsoft-edge-beta",            NULL,       NULL,       1 << 1,       0,           -1 },
    { "Lxappearance",                   NULL,       NULL,       0,            1,           -1 },
    { "VirtualBox",                     NULL,       NULL,       1 << 2,       1,           -1 },
    { "retroarch",                      NULL,       NULL,       1 << 4,       0,           -1 },
    { "obs",                            NULL,       NULL,       1 << 5,       0,           -1 },
    { "Peek",                           NULL,       NULL,       0,            1,           -1 },
    { "flameshot",                      NULL,       NULL,       0,            1,           -1 },
    { "feh",                            NULL,       NULL,       0,            1,           -1 },
    { "Gthumb",                         NULL,       NULL,       0,            1,           -1 },
    { "MPlayer",                        NULL,       NULL,       0,            1,           -1 },
    { "fcitx5-config-qt",               NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "",      tile },    /* first entry is default */
    { "",      NULL },    /* no layout function means floating behavior */
    { " ",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL};
static const char *alterWallpaper[] = { "/home/gin/suckless/dwm/scripts/dwm-wallpaper.sh", NULL};
static const char *screenLock[] = { "/home/gin/suckless/dwm/scripts/screen-lock.sh", NULL};
static const char *volUp[] = { "/home/gin/suckless/dwm/scripts/vol-up.sh", NULL};
static const char *volDown[] = { "/home/gin/suckless/dwm/scripts/vol-down.sh", NULL};
static const char *volTog[] = { "/home/gin/suckless/dwm/scripts/vol-toggle.sh", NULL};
static const char *backLightUp[] = { "/home/gin/suckless/dwm/scripts/backlight-up.sh", NULL};
static const char *backLightDown[] = { "/home/gin/suckless/dwm/scripts/backlight-down.sh", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
//static const char *roficmd[]  = { "rofi", "-show", "drun", NULL};
//static const char *rofiRun[]  = { "rofi", "-show", "run", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    //{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
    //{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
    //{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
    //{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
    //{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
    //{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
    //{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
    //{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
    //{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
    //{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
    //{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
    //{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
    //{ MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
    //{ MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
    //{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
    //{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
    //{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    //{ MODKEY,                       XK_p,      spawn,          {.v = roficmd } },
    //{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = rofiRun } },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_w,      spawn,          {.v = alterWallpaper } },
    { MODKEY|ShiftMask,             XK_l,      spawn,          {.v = screenLock } },
    { MODKEY,                       XK_s,      spawn,          {.v = flameshot } },
    { MODKEY,                       XK_F6,     spawn,          {.v = volUp } },
    { MODKEY,                       XK_F5,     spawn,          {.v = volDown } },
    { MODKEY,                       XK_F4,     spawn,          {.v = volTog } },
    { MODKEY,                       XK_F2,     spawn,          {.v = backLightUp} },
    { MODKEY,                       XK_F1,     spawn,          {.v = backLightDown} },
    { MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_e,      hidewin,        {0} },
    { MODKEY|ShiftMask,             XK_e,      restorewin,     {0} },
    { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY,                       XK_c,      killclient,     {0} },
    { MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button1,        togglewin,      {0} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

