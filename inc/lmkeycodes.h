/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmkeycodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:42 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/13 16:49:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* keycode */
#ifndef LMKEYCODES_H
# define LMKEYCODES_H
# ifdef __linux
#  include <X11/keysymdef.h>
#  define KEY_LEFT        0xff51
#  define KEY_RIGHT       0xff53
#  define KEY_DOWN        0xff54
#  define KEY_UP          0xff52
#  define KEY_A           0x0061
#  define KEY_D           0x0064
#  define KEY_S           0x0073
#  define KEY_W           0x0077
#  define KEY_ESC         0xff1b
#  define KEY_0           0x0030
#  define KEY_1           0x0031
#  define KEY_2           0x0032
#  define KEY_3           0x0033
#  define KEY_4           0x0034
#  define KEY_9           0x0039
# else
#  include "KVKcodes.h"
#  define KEY_LEFT        KVK_LEFT
#  define KEY_RIGHT       KVK_RIGHT
#  define KEY_DOWN        KVK_DOWN
#  define KEY_UP          KVK_UP
#  define KEY_A           KVK_A
#  define KEY_D           KVK_D
#  define KEY_S           KVK_S
#  define KEY_W           KVK_W
#  define KEY_ESC         KVK_ESCAPE
#  define KEY_0           KVK_0
#  define KEY_1           KVK_1
#  define KEY_2           KVK_2
#  define KEY_3           KVK_3
#  define KEY_4           KVK_4
#  define KEY_9           KVK_9
# endif
#endif
