/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmkeycodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:42 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/12 13:09:11 by aparolar         ###   ########.fr       */
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
#  define KEY_LEFT        123
#  define KEY_RIGHT       124
#  define KEY_DOWN        125
#  define KEY_UP          126
#  define KEY_A           0
#  define KEY_D           2
#  define KEY_S           1
#  define KEY_W           13
#  define KEY_SCROLLUP    5
#  define KEY_SCROLLDOWN  4
#  define KEY_SCROLLLEFT  6
#  define KEY_SCROLLRIGHT 7
#  define KEY_ESC         53
# endif
