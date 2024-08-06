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
* @file mk_list_remove.c
* @brief Définition de la fonction mk_list_remove.
* @date 22 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_list_remove ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkOffset )
{
   /* Si la liste comporte un seul élément */
   if ( p_mkList->current->next [ p_mkOffset ] == p_mkList->current )
   {
      /* Réinitialisation du pointeur de tâche */
      p_mkList->current = K_MK_NULL;
   }

   /* Sinon */
   else
   {
      /* Suppression de la tâche de la liste */
      p_mkTask->next[ p_mkOffset ]->previous [ p_mkOffset ] = p_mkTask->previous [ p_mkOffset ];
      p_mkTask->previous[ p_mkOffset ]->next [ p_mkOffset ] = p_mkTask->next [ p_mkOffset ];

      /* Si le pointeur de liste pointe sur la tâche à supprimer */
      if ( p_mkList->current == p_mkTask )
      {
         /* Réinitialisation du pointeur */
         p_mkList->current = p_mkTask->next [ p_mkOffset ];
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Configuration des pointeurs de la tâche */
   p_mkTask->next [ p_mkOffset ] = p_mkTask;
   p_mkTask->previous [ p_mkOffset ] = p_mkTask;

   /* Retour */
   return;
}


