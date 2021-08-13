/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmkeycodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:42 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/13 11:12:34 by aparolar         ###   ########.fr       */
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
#  include "kvkcodes.h"
#  define KEY_LEFT        kVK_LEFT
#  define KEY_RIGHT       kVK_RIGHT
#  define KEY_DOWN        kVK_DOWN
#  define KEY_UP          kVK_UP
#  define KEY_A           kVK_A
#  define KEY_D           kVK_D
#  define KEY_S           kVK_S
#  define KEY_W           kVK_W
#  define KEY_ESC         kVK_ESCAPE
#  define KEY_PLUS        kVK_PAD_ADD
#  define KEY_MINUS       kVK_MINUS
#  define KEY_0           kVK_0
#  define KEY_1           kVK_1
#  define KEY_2           kVK_2
#  define KEY_3           kVK_3
#  define KEY_4           kVK_4
#  define KEY_9           kVK_9
# endif
