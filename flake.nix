{
  description = "Following Kernighan & Ritchie C Programming Language Book";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, utils, nixpkgs }: utils.lib.eachDefaultSystem (system: 
    let
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShell = with pkgs; mkShell {
        buildInputs = [
          clang_18
        ];
      };
    }
  );
}
