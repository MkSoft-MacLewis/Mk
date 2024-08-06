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
* @file mk_termio_setChild.c
* @brief Définition de la fonction mk_termio_setChild.
* @date 16 juin 2019
*
*/

#include "mk_termio_api.h"


/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_termio_setChild ( T_mkTermio* p_termio, T_mkAddr p_child )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_ERROR_PARAM;

   /* Si les paramètres d'entrées sont valides */
   if ( ( p_termio != K_MK_NULL ) && ( p_child != K_MK_NULL ) )
   {
      /* Configuration de la structure de données du terminal */
      p_termio->child = p_child;

      /* Actualisation de la variable de retour */
      l_result = K_MK_OK;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}


