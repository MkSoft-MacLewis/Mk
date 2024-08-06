/**
*
* @copyright Copyright (C) 2018 RENARD Mathieu. All rights reserved.
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
* @file mk_mutex_unlock.c
* @brief Définition de la fonction mk_mutex_unlock.
* @date 10 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_mutex_unlock ( T_mkTask* p_mkUnused1, T_mkMutex* p_mkMutex, T_mkAddr p_mkUnused2, T_mkAddr p_mkUnused3, uint32_t p_mkUnused4 )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_OK;

   /* Ces paramètres sont présents en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkUnused1;
   ( void ) p_mkUnused2;
   ( void ) p_mkUnused3;
   ( void ) p_mkUnused4;

   /* Si le jeton peut être libéré */
   if ( p_mkMutex->lock == 1 )
   {
      /* Réinitialisation de l'objet de synchronisation */
      p_mkMutex->owner->synchro.object = K_MK_NULL;

      /* Réinitialisation de la variable de contrôle d'imbrication */
      p_mkMutex->owner->synchro.mutex = K_MK_NULL;

      /* Libération du mutex */
      p_mkMutex->lock = 0;
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_SYNC_KO;
   }

   /* Retour */
   return ( l_result );
}



