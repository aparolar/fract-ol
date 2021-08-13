/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmkeycodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:42 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/13 14:22:30 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* keycode */
# ifdef __linux
#  include <X11/keysymdef.h>
#  define KEY_LEFT        XK_Left
#  define KEY_RIGHT       XK_Right
#  define KEY_DOWN        XK_Down
#  define KEY_UP          XK_Up
#  define KEY_A           XK_A
#  define KEY_D           XK_D
#  define KEY_S           XK_S
#  define KEY_W           XK_W
#  define KEY_ESC         XK_Escape
#  define KEY_PLUS        XK_plus
#  define KEY_MINUS       XK_minus
#  define KEY_0           XK_0
#  define KEY_1           XK_1
#  define KEY_2           XK_2
#  define KEY_3           XK_3
#  define KEY_4           XK_4
#  define KEY_9           XK_9
# else
#  include "Events.h"
#  define KEY_LEFT        kVK_LeftArrow
#  define KEY_RIGHT       kVK_RightArrow
#  define KEY_DOWN        kVK_DownArrow
#  define KEY_UP          kVK_UpArrow
#  define KEY_A           kVK_ANSI_A
#  define KEY_D           kVK_ANSI_D
#  define KEY_S           kVK_ANSI_S
#  define KEY_W           kVK_ANSI_W
#  define KEY_ESC         kVK_Escape
#  define KEY_PLUS        kVK_ANSI_KeypadPlus
#  define KEY_MINUS       kVK_ANSI_Minus
#  define KEY_0           kVK_ANSI_0
#  define KEY_1           kVK_ANSI_1
#  define KEY_2           kVK_ANSI_2
#  define KEY_3           kVK_ANSI_3
#  define KEY_4           kVK_ANSI_4
#  define KEY_9           kVK_ANSI_9
# endif
