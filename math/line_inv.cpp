inv[1]=1;
rep(i,2,n+1) inv[i]=(mod-mod/i)*inv[mod%i]%mod; 
