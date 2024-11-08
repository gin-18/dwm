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
static const char *fonts[]                  = { "FiraCode Nerd Font Mono:pixelsize=24:style=Medium:antialias=true:autohint=true" };
static const char dmenufont[]               = "FiraCode Nerd Font Mono:pixelsize=24:style=Medium:antialias=true:autohint=true";
/* colors catppuccin-frappe */
static const char rosewater[]               = "#f5e0dc";
static const char flamingo[]                = "#f2cdcd";
static const char pink[]                    = "#f5c2e7";
static const char mauve[]                   = "#cba6f7";
static const char red[]                     = "#f38ba8";
static const char maroon[]                  = "#eba0ac";
static const char peach[]                   = "#fab387";
static const char yellow[]                  = "#f9e2af";
static const char green[]                   = "#a6e3a1";
static const char teal[]                    = "#94e2d5";
static const char sky[]                     = "#89dceb";
static const char sapphire[]                = "#74c7ec";
static const char blue[]                    = "#89b4fa";
static const char lavender[]                = "#b4befe";
static const char text[]                    = "#cdd6f4";
static const char subtext1[]                = "#bac2de";
static const char subtext0[]                = "#a6adc8";
static const char overlay2[]                = "#9399b2";
static const char overlay1[]                = "#7f849c";
static const char overlay0[]                = "#6c7086";
static const char surface2[]                = "#585b70";
static const char surface1[]                = "#45475a";
static const char surface0[]                = "#313244";
static const char base[]                    = "#1e1e2e";
static const char mantle[]                  = "#181825";
static const char crust[]                   = "#11111b";

static const char *colors[][3] = {
    /*                    fg     bg      border */
    [SchemeNorm]      = { text,  base,     mantle   },
    [SchemeSel]       = { text,  surface0, subtext0 },
    [SchemeHid]       = { text,  base,     base     },
    [SchemeStatus]    = { text,  base,     base     }, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel]   = { crust, blue,     base     }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { text,  base,     base     }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]   = { text,  base,     base     }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { text,  base,     base     }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "", "", "", "󰍹" };

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
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "wezterm", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL};
static const char *alterWallpaper[] = { "/home/gin/github/gin-18/dwm/scripts/dwm-wallpaper.sh", NULL};
static const char *screenLock[] = { "/home/gin/github/gin-18/dwm/scripts/screen-lock.sh", NULL};
static const char *volUp[] = { "/home/gin/github/gin-18/dwm/scripts/vol-up.sh", NULL};
static const char *volDown[] = { "/home/gin/github/gin-18/dwm/scripts/vol-down.sh", NULL};
static const char *volTog[] = { "/home/gin/github/gin-18/dwm/scripts/vol-toggle.sh", NULL};
static const char *backLightUp[] = { "/home/gin/github/gin-18/dwm/scripts/backlight-up.sh", NULL};
static const char *backLightDown[] = { "/home/gin/github/gin-18/dwm/scripts/backlight-down.sh", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    //{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
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

