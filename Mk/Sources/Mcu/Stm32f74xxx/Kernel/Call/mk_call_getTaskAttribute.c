/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_call_getTaskAttribute.c
* @brief Définition de la fonction mk_call_getTaskAttribute.
* @date 22 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_getTaskAttribute ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Déclaration d'un variable stockant l'offset de l'attribut à récupérer */
   uint32_t l_offset = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_ARG ];

   /* Vérification de l'alignement de l'adresse */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                sizeof ( T_mkTask ), ( T_mkAddr ) l_task );

   /* Si la tâche est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Si l'offset est valide */
      if ( ( l_offset <= K_MK_CURRENT_PRIORITY ) )
      {
         /* Récupération de l'adresse de l'attribut demandé */
         p_mkObject->handle = ( T_mkAddr ) ( uint32_t ) ( * ( uint32_t* ) ( ( &l_task->attribute.identifier ) + l_offset ) );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_PARAM;
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien fiare */
   }

   /* Retour */
   return;
}


