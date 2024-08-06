/**
*
* @copyright Copyright (C) 2023 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_display_plane2d_types.h
* @brief Déclaration des types dédiés au module 'Plane2d'.
* @date 4 août 2023
*
*/

#ifndef MK_DISPLAY_PLANE2D_TYPES_H
#define MK_DISPLAY_PLANE2D_TYPES_H

/**
 * @struct T_mkPlane2D
 * @brief Déclaration de la structure T_mkPlane2D.
 */

typedef struct T_mkPlane2D T_mkPlane2D;
struct T_mkPlane2D
{
   real32_t x;             /*!< Ce membre contient la composante 'x' du plan. */
   real32_t y;             /*!< Ce membre contient la composante 'y' du plan. */
   uint32_t width;         /*!< Ce membre contient la composante 'Width' du plan. */
   uint32_t height;        /*!< Ce membre contient la composante 'Height' du plan. */
};

/**
 * @struct T_mkPlane2Di
 * @brief Déclaration de la structure T_mkPlane2Di.
 */

typedef struct T_mkPlane2Di T_mkPlane2Di;
struct T_mkPlane2Di
{
   uint32_t x;             /*!< Ce membre contient la composante 'x' du plan. */
   uint32_t y;             /*!< Ce membre contient la composante 'y' du plan. */
   uint32_t width;         /*!< Ce membre contient la composante 'Width' du plan. */
   uint32_t height;        /*!< Ce membre contient la composante 'Height' du plan. */
};

/**
 *
 */

#endif
