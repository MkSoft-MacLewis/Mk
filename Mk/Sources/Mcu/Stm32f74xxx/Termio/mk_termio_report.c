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
* @file mk_termio_report.c
* @brief Définition de la fonction mk_termio_report.
* @date 30 avr. 2023
*
*/

#include "mk_termio_api.h"
#include "mk_supervisor_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_termio_report ( T_mkCode p_code )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un message */
   T_mkSupervisorMessage l_message = { 0 };

   /* Enregistrement du code retour dans le message */
   l_message.returnValue = p_code;

   /* Transmission du message au superviseur afin qu'il édite un rapport d'erreur. */
   l_result = mk_supervisor_post ( K_MK_SUPERVISOR_TASKFAULT, &l_message );

   /* Retour */
   return ( l_result );
}

