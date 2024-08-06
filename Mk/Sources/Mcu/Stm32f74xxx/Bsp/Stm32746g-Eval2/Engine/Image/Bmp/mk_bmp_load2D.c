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
* @file mk_bmp_load2D.c
* @brief Définition de la fonction mk_bmp_load2D.
* @date 1 janv. 2023
*
*/

#include "mk_engine_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_bmp_load2D ( T_mkBMPFile* p_bitmap, T_mkAddr p_addr, uint32_t p_bytesPerPixel, uint8_t p_alpha )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'une requête */
   T_mkDisplayRequest l_request = { K_MK_DISPLAY_REQUEST_TYPE_CHROMART, { { K_MK_DISPLAY_REQUEST_CHROMART_LOAD, { 0, 0, 0, 0 }, { { 0 } } } } };

   /* Si les paramètres sont valides */
   if ( ( p_bitmap != K_MK_NULL ) && ( p_bitmap->file != K_MK_NULL ) )
   {
      /* Configuration des attributs de la requête */
      mk_chromart_setLoad ( &l_request.content.chromart, p_bitmap, p_addr, p_bytesPerPixel, p_alpha );

      /* Déploiement du bitmap en mémoire */
      l_result = mk_display_postRequest ( &l_request );
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


