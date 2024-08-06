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
* @file mk_system_memory_init.c
* @brief Définition de la fonction mk_system_memory_init.
* @date 9 mars 2019
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_sysCode mk_system_memory_init ( void )
{
   /* Déclaration de la variable de retour */
   T_sysCode l_result = K_SYS_OK;

   /* Déclaration d'une variable de travail */
   uint32_t l_ret;

   /* Initialisation des broches GPIO des mémoires */
   mk_system_memory_initGPIO ( );

   /* Initialisation de ou des mémoires SRAM */
   mk_system_memory_initSRAM ( );

   /* Initialisation de ou des mémoires SDRAM */
   l_ret = mk_system_memory_initSDRAM ( );

   /* Si une erreur s'est produite */
   if ( l_ret != K_SDRAM_OK )
   {
      /* Actualisation de la variable de retour */
      l_result = K_SYS_ERROR_SDRAM;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Initialisation de ou des mémoires QSPI */
   l_ret = mk_system_memory_initQSPI ( K_QSPI_INSTRUCTION_QUAD_MODE );

   /* Si une erreur s'est produite */
   if ( l_ret != K_QSPI_OK )
   {
      /* Actualisation de la variable de retour */
      l_result = K_SYS_ERROR_QSPI;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}



