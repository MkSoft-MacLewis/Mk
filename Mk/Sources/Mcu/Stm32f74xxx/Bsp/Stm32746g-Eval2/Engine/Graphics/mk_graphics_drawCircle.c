/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file mk_graphics_drawCircle.c
* @brief Définition de la fonction mk_graphics_drawCircle.
* @date 2 avr. 2019
*
*/

#include "mk_engine_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_graphics_postCircleRequest ( uint32_t p_layer, uint32_t p_state, uint32_t p_x, uint32_t p_y, uint32_t p_radius, uint32_t p_argb )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'une requête */
   T_mkDisplayRequest l_request = { K_MK_DISPLAY_REQUEST_TYPE_CHROMART, { { K_MK_DISPLAY_REQUEST_CHROMART_CIRCLE, { 0, 0, 0, 0 }, { { 0 } } } } };

   /* Configuration des attributs de la requête */
   mk_chromart_setPlane ( &l_request.content.chromart.plane, p_x, p_y, 0, 0 );
   mk_chromart_setCircle ( &l_request.content.chromart, p_layer, p_state, p_radius, p_argb );

   /* Transmission de la requête */
   l_result = mk_display_postRequest ( &l_request );

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_graphics_drawCircle ( uint32_t p_layer, uint32_t p_state, T_mkVect2D p_v, real32_t p_radius, uint32_t p_argb )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration des vecteurs de travail */
   T_mkVect2D l_r1, l_r2;

   /* Conversion des coordonnées du vecteur v en entier */
   p_v.x = mk_vect2d_shift ( p_v.x );
   p_v.y = mk_vect2d_shift ( p_v.y );

   /* Conversion du rayon en entier */
   p_radius = mk_vect2d_shift ( p_radius );

   /* Conversion des coordonnées du vecteur vr en entier */
   l_r1.x = mk_vect2d_shift ( p_v.x + p_radius ) - 1.0f;
   l_r1.y = mk_vect2d_shift ( p_v.y + p_radius ) - 1.0f;

   /* Conversion des coordonnées du vecteur vr en entier */
   l_r2.x = mk_vect2d_shift ( p_v.x - p_radius );
   l_r2.y = mk_vect2d_shift ( p_v.y - p_radius );

   /* Détermination de la validité des paramètres */
   l_result = mk_graphics_checkVertex ( &p_v, &l_r1, &l_r2, ( real32_t ) g_mkDisplay.screen.width, ( real32_t ) g_mkDisplay.screen.height );

   /* Si les paramètres sont conformes */
   if ( ( l_result == K_MK_OK ) && ( p_layer <= K_MK_GRAPHICS_BACKGROUND ) )
   {
      /* Transmission de la requête */
      l_result = mk_graphics_postCircleRequest ( p_layer, p_state, ( uint32_t ) p_v.x, ( uint32_t ) p_v.y, ( uint32_t ) p_radius, p_argb );
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Retour */
   return ( l_result );
}



